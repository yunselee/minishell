/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:16:25 by yunselee          #+#    #+#             */
/*   Updated: 2022/03/31 16:32:33 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../exit_code/exit_code.h"
#include <fcntl.h>
#include <unistd.h>
#include "../allow_function/allow_function.h"
#include "../as_tree/as_tree.h"
#include <stdio.h>
#include <readline/readline.h>
#include "../stdio_manager/stdio_manager.h"
#include "sig.h"

#define CHILD 0

#define READ 0
#define WRITE 1

#define HEREDOC_DIR "./.heredoc"

void	wait_pid_and_set_exit_code(pid_t child);
void	connect_file_to_std(const char *pathname, int path_open_flags, \
			 int path_open_mode, int std_fd);
void	execute_basic_cmd(t_node *astree);
void	execute_recursive(t_node *astree);

static void	close_pointer(int pipe_fd[])
{
	close(pipe_fd[WRITE]);
	close(pipe_fd[READ]);
}

static void	set_pipe_recursive(t_node *astree)
{
	int		pipe_fd[2];
	pid_t	child;

	_pipe(pipe_fd);
	child = _fork();
	if (child == CHILD)
	{
		sig_set_child();
		_dup2(pipe_fd[WRITE], STDOUT_FILENO);
		close_pointer(pipe_fd);
		execute_recursive(astree->left);
		exit(EXIT_SUCCESS);
	}
	wait_pid_and_set_exit_code(child);
	child = _fork();
	if (child == CHILD)
	{
		sig_set_child();
		_dup2(pipe_fd[READ], STDIN_FILENO);
		close_pointer(pipe_fd);
		execute_recursive(astree->right);
		exit(EXIT_SUCCESS);
	}
	wait_pid_and_set_exit_code(child);
	close_pointer(pipe_fd);
}

static void	execute_heredoc(t_node *astree)
{
	const char	*eof = astree->right->data;
	const pid_t	child = fork();
	int			fd;
	char		*line;

	if (child == CHILD)
	{
		stdio_recover();
		fd = _open(HEREDOC_DIR, O_TRUNC | O_WRONLY | O_CREAT, S_IRWXU);
		line = readline("> ");
		while (ft_strncmp(line, eof, ft_strlen(eof)) \
			|| ft_strlen(line) != ft_strlen(eof))
		{
			ft_putendl_fd(line, fd);
			free(line);
			line = readline("> ");
		}
		free(line);
		close(fd);
		exit(EXIT_SUCCESS);
	}
	wait_pid_and_set_exit_code(child);
	connect_file_to_std(HEREDOC_DIR, O_RDONLY, S_IRWXU, STDIN_FILENO);
}

static void	set_rdr_recursive(t_node *astree)
{
	const char	*path = astree->right->data;
	int			file_fd;

	if (astree->cmd_type == CMD_TYPE_R_SHIFT)
	{
		connect_file_to_std(path, O_WRONLY | O_CREAT, S_IRWXU, STDOUT_FILENO);
	}
	else if (astree->cmd_type == CMD_TYPE_RD_SHIFT)
	{
		connect_file_to_std(path, O_WRONLY | O_CREAT | O_APPEND, \
									S_IRWXU, STDOUT_FILENO);
	}
	else if (astree->cmd_type == CMD_TYPE_L_SHIFT)
	{
		file_fd = _open(path, O_RDONLY, S_IRWXU);
		if (file_fd == -1)
			return ;
		_dup2(file_fd, STDIN_FILENO);
		_close(file_fd);
	}
	else if (astree->cmd_type == CMD_TYPE_LD_SHIFT)
	{
		execute_heredoc(astree);
	}
	execute_recursive(astree->left);
}

void	execute_recursive(t_node *astree)
{
	if (astree->cmd_type == CMD_TYPE_PIPE)
	{
		set_pipe_recursive(astree);
		return ;
	}
	else if (astree->cmd_type == CMD_TYPE_L_SHIFT \
		|| astree->cmd_type == CMD_TYPE_LD_SHIFT \
		|| astree->cmd_type == CMD_TYPE_R_SHIFT \
		|| astree->cmd_type == CMD_TYPE_LD_SHIFT)
	{
		set_rdr_recursive(astree);
		return ;
	}
	execute_basic_cmd(astree);
	unlink(HEREDOC_DIR);
}
