/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghyk <seunghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:39:02 by seunghyk          #+#    #+#             */
/*   Updated: 2022/03/29 19:39:04 by seunghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>
#include <dirent.h>
#include "libft/libft.h"
#include "command_initializer/command_initializer.h"
#include "env_variable/env_variable.h"
#include "as_tree/as_tree.h"
#include "stdio_manager/stdio_manager.h"
#include "execute/execute.h"
#include "sig/sig.h"
#include "allow_function.h"

static void	register_all_env(const char **envp)
{
	const char	**p_envp;
	char		**tokens;
	int			i;

	p_envp = envp;
	while (*p_envp != NULL)
	{
		tokens = ft_split(*p_envp, '=');
		register_env_variable(tokens[0], tokens[1]);
		i = 0;
		while (tokens[i] != NULL)
		{
			_free(tokens[i]);
			i++;
		}
		_free(tokens);
		++p_envp;
	}
}

static bool	try_excute_command(char *text)
{
	t_command	command;
	t_node		*root;

	root = NULL;
	if (try_init_command(text, &command))
	{
		if (ft_strcmp(command.tokens[0], "exit") == 0)
		{
			exit(EXIT_SUCCESS);
		}
		stdio_back_up();
		root = init_astree_malloc(&command);
		execute_recursive(root);
		destroy_astree(root);
		stdio_recover();
		stdio_close_back_up();
	}
	return (true);
}

int	main(int argc, const char **argv, const char **envp)
{
	char		*text;

	(void)argc;
	(void)argv;
	register_all_env(envp);
	sig_set();
	while (1)
	{
		text = readline("Prompt :");
		{
			if (text == NULL)
				return (EXIT_SUCCESS);
			if (!try_excute_command(text))
			{
				free(text);
				return (EXIT_SUCCESS);
			}
		}
		free(text);
	}
	return (EXIT_SUCCESS);
}
