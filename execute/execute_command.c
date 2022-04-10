/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:16:25 by yunselee          #+#    #+#             */
/*   Updated: 2022/04/10 17:52:59 by yunselee         ###   ########.fr       */
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
#define HEREDOC_PROMPT "\e[32m> \e[0m"
#define HEREDOC_DIR "./.heredoc"

void	wait_pid_and_set_exit_code(pid_t child);
void	connect_file_to_std(const char *pathname, int path_open_flags, \
			int path_open_mode, int std_fd);
void	execute_basic_cmd(t_node *astree);
void	execute_recursive(t_node *astree);
void	close_pointer(int pipe_fd[]);

static void	set_pipe_recursive(t_node *astree)
{
	int		pipe_fd[2];
	pid_t	child[2];

	_pipe(pipe_fd);
	sig_disable();
	child[0] = _fork();
	if (child[0] == CHILD)
	{
		_dup2(pipe_fd[WRITE], STDOUT_FILENO);
		close_pointer(pipe_fd);
		execute_recursive(astree->left);
		exit(EXIT_SUCCESS);
	}
	child[1] = _fork();
	if (child[1] == CHILD)
	{
		_dup2(pipe_fd[READ], STDIN_FILENO);
		close_pointer(pipe_fd);
		execute_recursive(astree->right);
		exit(exit_code_get_latest());
	}
	close_pointer(pipe_fd);
	wait_pid_and_set_exit_code(child[0]);
	wait_pid_and_set_exit_code(child[1]);
	sig_set();
}

static void	exeucte_heredoc_child(const char	*eof)
{
	int			fd;
	char		*line;

	stdio_recover();
	sig_set_heredoc();
	fd = _open(HEREDOC_DIR, O_TRUNC | O_WRONLY | O_CREAT, S_IRWXU);
	line = readline(HEREDOC_PROMPT);
	if (line == NULL)
		exit(EXIT_FAILURE);
	while (line == NULL && ft_strcmp(line, eof) != 0)
	{
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
		line = readline(HEREDOC_PROMPT);
	}
	free(line);
	close(fd);
	exit(EXIT_SUCCESS);
}

static void	execute_heredoc(t_node *astree)
{
	const char	*eof = astree->right->data;
	pid_t		child;

	sig_disable();
	child = _fork();
	if (child == CHILD)
	{
		exeucte_heredoc_child(eof);
	}
	wait_pid_and_set_exit_code(child);
	sig_set();
	connect_file_to_std(HEREDOC_DIR, O_RDONLY, S_IRWXU, STDIN_FILENO);
}

static void	set_rdr_recursive(t_node *astree)
{
	const char	*path = astree->right->data;
	int			file_fd;

	if (astree->cmd_type == CMD_TYPE_R_SHIFT)
		connect_file_to_std(path, O_TRUNC | O_WRONLY | \
									O_CREAT, S_IRWXU, STDOUT_FILENO);
	else if (astree->cmd_type == CMD_TYPE_RD_SHIFT)
		connect_file_to_std(path, O_WRONLY | O_CREAT | O_APPEND, \
									S_IRWXU, STDOUT_FILENO);
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
		if (exit_code_get_latest() == EXIT_FAILURE)
			return ;
	}
	execute_recursive(astree->left);
}

void	execute_recursive(t_node *astree)
{
	if (astree == NULL)
		return ;
	if (astree->cmd_type == CMD_TYPE_PIPE)
	{
		set_pipe_recursive(astree);
		return ;
	}
	else if (astree->cmd_type == CMD_TYPE_L_SHIFT \
		|| astree->cmd_type == CMD_TYPE_LD_SHIFT \
		|| astree->cmd_type == CMD_TYPE_R_SHIFT \
		|| astree->cmd_type == CMD_TYPE_RD_SHIFT)
	{
		set_rdr_recursive(astree);
		return ;
	}
	execute_basic_cmd(astree);
	unlink(HEREDOC_DIR);
}
