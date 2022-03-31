/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghyk <seunghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:03:30 by yunselee          #+#    #+#             */
/*   Updated: 2022/03/31 18:43:17 by seunghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "../exit_code/exit_code.h"
#include "builtin.h"
#include "../env_variable/env_variable.h"
#include "../libft/libft.h"
#include <stdio.h>

char	*tokenize(char *str_or_null, const char *delims);
void	sort(char **envs);

static bool	is_valid_key(const char *key)
{
	const char	*p_key;

	p_key = key;
	if (!ft_isalpha(*p_key++))
	{
		return (false);
	}
	while (ft_isalnum(*p_key))
	{
		++p_key;
	}
	if (*p_key != '\0')
	{
		return (false);
	}
	return (true);
}

static void	print_sorted_envs(void)
{
	char	**envs;
	int		i;

	i = 0;
	envs = get_all_env_malloc();
	sort(envs);
	while (envs[i] != NULL)
		printf("declare -x %s\n", envs[i++]);
	destroy_envs(envs);
}

void	builtin_export(char **args)
{
	char	*key;
	char	*value;
	int		i;

	exit_code_set(EXIT_SUCCESS);
	if (args[1] == NULL)
	{
		print_sorted_envs();
	}
	i = 1;
	while (args[i] != NULL)
	{
		key = tokenize(args[i++], "=");
		value = tokenize(NULL, "=");
		if (!is_valid_key(key))
		{
			printf("export: \'%s=%s\': not a valid identifier\n", key, value);
			exit_code_set(1);
			continue ;
		}
		register_env_variable(key, value);
	}
}
