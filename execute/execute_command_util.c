/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command_util.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:18:42 by yunselee          #+#    #+#             */
/*   Updated: 2022/04/10 20:12:56 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include "allow_function.h"
#include "exit_code.h"
#include "libft.h"

void	wait_pid_and_set_exit_code(pid_t child)
{
	int	exit_code;

	_waitpid(child, &exit_code, 0);
	exit_code = (exit_code >> 8) & 0x000000ff;
	exit_code_set(exit_code);
}

void	connect_file_to_std(const char *pathname, \
	int path_open_flags, int path_open_mode, int std_fd)
{
	const int	file_fd = _open(pathname, path_open_flags, path_open_mode);

	if (file_fd == -1)
		return ;
	_dup2(file_fd, std_fd);
	_close(file_fd);
}

void	close_pointer(int pipe_fd[])
{
	_close(pipe_fd[0]);
	_close(pipe_fd[1]);
}

bool	is_minishell(const char *arg)
{
	const char	*minishell = "minishell";
	const int	minishell_len = ft_strlen(minishell);
	const int	arglen = ft_strlen(arg);

	return (ft_strcmp(arg + arglen - minishell_len, minishell) == 0);
}
