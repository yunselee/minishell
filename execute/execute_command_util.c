/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command_util.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:18:42 by yunselee          #+#    #+#             */
/*   Updated: 2022/03/31 21:07:51 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include "../allow_function/allow_function.h"
#include "../exit_code/exit_code.h"
#include "libft.h"

void	wait_pid_and_set_exit_code(pid_t child)
{
	int	exit_code;

	_waitpid(child, &exit_code, 0);
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
	close(pipe_fd[0]);
	close(pipe_fd[1]);
}

bool	is_minishell(const char *arg)
{
	const char	*minishell = "minishell";
	const int	minishell_len = ft_strlen(minishell);
	const int	arglen = ft_strlen(arg);

	return (ft_strcmp(arg + arglen - minishell_len, minishell) == 0);
}
