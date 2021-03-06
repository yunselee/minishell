/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:39:02 by seunghyk          #+#    #+#             */
/*   Updated: 2022/04/10 20:14:51 by yunselee         ###   ########.fr       */
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
#include "libft.h"
#include "command_initializer.h"
#include "env_variable.h"
#include "as_tree.h"
#include "stdio_manager.h"
#include "execute.h"
#include "sig.h"
#include "allow_function.h"

#define PROMPT "Prompt :"

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

static void	excute_command(char *text)
{
	t_command	command;
	t_node		*root;

	root = NULL;
	if (!try_init_command(text, &command))
	{
		return ;
	}
	stdio_back_up();
	root = init_astree_malloc(&command);
	execute_recursive(root);
	destroy_astree(root);
	stdio_recover();
	stdio_close_back_up();
}

int	main(int argc, const char **argv, const char **envp)
{
	char	*text;

	(void)argc;
	(void)argv;
	register_all_env(envp);
	sig_set();
	while (1)
	{
		text = readline(PROMPT);
		{
			if (text == NULL)
				return (EXIT_SUCCESS);
			excute_command(text);
		}
		free(text);
	}
	return (EXIT_SUCCESS);
}
