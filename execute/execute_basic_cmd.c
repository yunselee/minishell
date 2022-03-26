#include "./builtin/builtin.h"
#include "libft/libft.h"
#include "exit_code.h"
#include <fcntl.h>
#include <unistd.h>
#include "./env_variable/env_variable.h"
#include "./allow_function/allow_function.h"
#include "sig.h"
#include "as_tree.h"

// fork하고 내부에서 처리
#define CHILD 0

static void fork_and_exe(const char **args)
{
	pid_t	child;

	sig_disable();
	child = _fork();
	if (child == CHILD)
	{
		execve_child_process(args);
		exit (EXIT_FAILURE);
	}
	wait_pid_and_set_exit_code(child);
	sig_set();
}

// no return
static void	execve_child_process(char **args)
{
	const char	**p_envp = get_all_env();
	const char	**p_env_path = ft_split(get_env_variable_or_null("PATH"), ':');
	char	*p_cmd;
	char	*p_tmp;
	int		i;

	i = 0;
	while (p_env_path[i] != NULL)
	{
		p_tmp = ft_strjoin(p_env_path[i], "\\");
		p_cmd = ft_strjoin(p_tmp, args[0]);
		_execve(p_cmd, args, p_envp);
		_free(p_tmp);
		_free(p_cmd);
		i++;
	}
	printf("%s : command not found\n", args[0]);
}

static char	**make_args(const t_node *astree)
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
		free(args[i]);
		++i;
	}
	free(args);
}

void	execute_basic_cmd(t_node *astree)
{
	const char	**args = make_args(astree);
	const char	*command = args[0];

	if (ft_strcmp(command, "cd") == 0)
		builtin_cd(args);
	else if (ft_strcmp(command, "echo") == 0)
		builtin_echo(args);
	else if (ft_strcmp(command, "pwd") == 0)
		builtin_pwd();
	else if (ft_strcmp(command, "env") == 0)
		builtin_env();
	else if (ft_strcmp(command, "export") == 0)
		builtin_export(args);
	else if (ft_strcmp(command, "unset") == 0)
		builtin_unset(args);
	else
		fork_and_exe(args);
	clear_args(args);
}
