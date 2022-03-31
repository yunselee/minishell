/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghyk <seunghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:03:30 by yunselee          #+#    #+#             */
/*   Updated: 2022/03/31 16:16:03 by seunghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../exit_code/exit_code.h"
#include "builtin.h"
#include "../env_variable/env_variable.h"
#include "../libft/libft.h"
#include <stdio.h>

static int	partition(char **envs, int left, int right)
{
	char	*pivotKey;
	int		pivotPos;
	int		i;
	char	*temp;

	pivotKey = envs[right];
	pivotPos = left;
	i = left;
	while (i < right)
	{
		if (0 < ft_strcmp(pivotKey, envs[i]))
		{
			temp = envs[pivotPos];
			envs[pivotPos] = envs[i];
			envs[i] = temp;
			++pivotPos;
		}
		++i;
	}
	return (pivotPos);
}

static void	sort_recursive(char **envs, int left, int right)
{
	char	*temp;
	int		pivot;

	if (right <= left)
	{
		return ;
	}
	pivot = partition(envs, left, right);
	temp = envs[pivot];
	envs[pivot] = envs[right];
	envs[right] = temp;
	sort_recursive(envs, left, pivot - 1);
	sort_recursive(envs, pivot + 1, right);
}

static void	sort(char **envs)
{
	char	**p_envs;
	int		n;

	p_envs = envs;
	n = 0;
	while (*p_envs != NULL)
	{
		++n;
		++p_envs;
	}
	sort_recursive(envs, 0, n - 1);
}

static char	*tokenize(char *str_or_null, const char *delims)
{
	static char	*s_str = NULL;
	char		*token;

	if (str_or_null != NULL)
		s_str = str_or_null;
	else if (s_str == NULL)
		return (NULL);
	while (*s_str != '\0' && ft_strchr(delims, *s_str) != NULL)
		++s_str;
	token = s_str;
	while (*s_str != '\0' && ft_strchr(delims, *s_str) == NULL)
		++s_str;
	if (*s_str == '\0')
		s_str = NULL;
	else
		*s_str++ = '\0';
	if (*token == '\0')
		return (NULL);
	return (token);
}

void	builtin_export(char **args)
{
	char	*key;
	char	*value;
	int		i;
	char	**envs;

	if (args[1] == NULL)
	{
		i = 0;
		envs = get_all_env_malloc();
		sort(envs);
		while (envs[i] != NULL)
		{
			printf("declare -x %s\n", envs[i]);
			i++;
		}
		destroy_envs(envs);
	}
	i = 1;
	while (args[i] != NULL)
	{
		key = tokenize(args[i], "=");
		value = tokenize(NULL, "=");
		register_env_variable(key, value);
		i++;
	}
	exit_code_set(EXIT_SUCCESS);
}
