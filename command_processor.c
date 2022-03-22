#include "./builtin/builtin.h"
#include "libft/libft.h"
#include "exit_code.h"
// fork하고 내부에서 처리
#define CHILD 0

void	process_command(char *command, char **tokens, int token_size)
{
	if (!ft_strcmp(command, "cd"))
		builtin_cd(tokens, token_size);
	else if (!ft_strcmp(command, "echo"))
		builtin_echo(tokens, token_size);
	else if (!ft_strcmp(command, "pwd"))
		builtin_pwd();
	else if (!ft_strcmp(command, "env"))
		builtin_env();
	else if (!ft_strcmp(command, "export"))
		builtin_export(tokens, token_size);
	else if (!ft_strcmp(command, "unset"))
		builtin_unset(tokens, token_size);
	else
		execve();
	return (0);
}

void	process()
{
	int			exit_code;
	const pid_t	pid = fork();

	if (pid == CHILD)
	{
		//child process
		process_command(token, token_size);
	}
	wait(&exit_code);
	set_exit_code(exit_code);
}