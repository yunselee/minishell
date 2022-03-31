/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_basic_cmd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:38:44 by yunselee          #+#    #+#             */
/*   Updated: 2022/03/31 22:25:41 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtin/builtin.h"
#include "../libft/libft.h"
#include "../exit_code/exit_code.h"
#include <fcntl.h>
#include <unistd.h>
#include "../env_variable/env_variable.h"
#include "../allow_function/allow_function.h"
#include "../sig/sig.h"
#include "../as_tree/as_tree.h"
#include "../sig/sig.h"
#include <stdio.h>

// fork하고 내부에서 처리
#define CHILD 0

bool	is_minishell(const char *arg);
void	wait_pid_and_set_exit_code(pid_t child);

// no return
static void	execve_child_process(char **args)
{
	char	**p_envp;
	char	**p_env_path;
	char	*p_cmd;
	char	*p_tmp;
	int		i;

	i = 0;
	p_envp = get_all_env_malloc();
	p_env_path = ft_split(get_env_variable_or_null("PATH"), ':');
	while (p_env_path[i] != NULL)
	{
		p_tmp = ft_strjoin(p_env_path[i], "/");
		p_cmd = ft_strjoin(p_tmp, args[0]);
		_execve(p_cmd, args, p_envp);
		_free(p_tmp);
		_free(p_cmd);
		i++;
	}
	_execve(args[0], args, p_envp);
	printf("%s : command not found\n", args[0]);
}

static void	fork_and_exe(char **args)
{
	pid_t	child;

	if (is_minishell(args[0]))
		sig_disable();
	else
		sig_set_execve();
	child = _fork();
	if (child == CHILD)
	{
		execve_child_process(args);
		exit (127);
	}
	wait_pid_and_set_exit_code(child);
	sig_set();
}

static char	**make_args(t_node *astree)
{
	char	**args;
	int		argc;
	t_node	*curr;
	int		i;

	argc = 0;
	curr = astree;
	while (curr != NULL)
	{
		argc++;
		curr = curr->right;
	}
	args = (char **)malloc(sizeof(char *) * (argc + 1));
	i = 0;
	curr = astree;
	while (curr != NULL)
	{
		args[i++] = ft_strdup(curr->data);
		curr = curr->right;
	}
	args[i] = NULL;
	return (args);
}

static void	clear_args(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
	{
		_free(args[i]);
		++i;
	}
	_free(args);
}

void	execute_basic_cmd(t_node *astree)
{
	char	**args;
	char	*command;

	args = make_args(astree);
	command = args[0];
	if (ft_strcmp(command, "cd") == 0)
		builtin_cd((const char **)args);
	else if (ft_strcmp(command, "echo") == 0)
		builtin_echo((const char **)args);
	else if (ft_strcmp(command, "pwd") == 0)
		builtin_pwd();
	else if (ft_strcmp(command, "env") == 0)
		builtin_env();
	else if (ft_strcmp(command, "export") == 0)
		builtin_export(args);
	else if (ft_strcmp(command, "unset") == 0)
		builtin_unset((const char **)args);
	else if (ft_strcmp(command, "exit") == 0)
		builtin_exit((const char **)args);
	else
		fork_and_exe(args);
	clear_args(args);
}
