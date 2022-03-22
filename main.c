#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>
#include <dirent.h>
#include "libft/libft.h"
#include "command_processor.h"
#include "command_initializer/command_initializer.h"
#include "env_variable/env_variable.h"

static void print_command(t_command *command);
static void register_all_env(const char **envp);

int main(int argc, const char **argv, const char **envp)
{
	t_command	command;
	char		**tokens;
	char		*text;
	
	register_all_env(envp);
	while (1)
	{
		text = readline("Prompt :");
		{
			if (try_init_command(text, &command))
			{
				if (ft_strncmp(command.tokens[0], "exit", 4) == 0)
				{
					free(text);
					return (0);
				}
				print_command(&command);
				//tokens = command.tokens;
				//process_command(tokens[0], &tokens[1], command.num_token - 1);
			}
		}
		free(text);
	}
	return (0);
}

static void print_command(t_command *command)
{
	int i;

	i = 0;
	while (i < command->num_token)
	{
		printf("%s\n", command->tokens[i]);
		++i;
	}
}

static void register_all_env(const char **envp)
{
	const char	**p_envp;
	char		**tokens;

	p_envp = envp;
	while (*p_envp != NULL)
	{
		tokens = ft_split(*p_envp, '=');
		register_env_variable(tokens[0], tokens[1]);
		free(tokens[0]);
		free(tokens[1]);
		++p_envp;
	}
}