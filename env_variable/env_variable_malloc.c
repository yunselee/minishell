/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_variable_malloc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghyk <seunghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:30:02 by seunghyk          #+#    #+#             */
/*   Updated: 2022/04/05 16:15:45 by seunghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "env_variable.h"

extern t_env_variable_list	g_variables;

char	**get_all_env_malloc(void)
{
	char				**pa_combined;
	char				*p_combined;
	char				*p_src;
	int					i;

	i = 0;
	pa_combined = (char **)malloc(sizeof(char *) * (MAX_ENV + 1));
	while (i < g_variables.size)
	{
		pa_combined[i] = (char *)malloc(sizeof(char)
				* (MAX_KEY_LENGTH + MAX_VALUE_LENGTH));
		p_combined = pa_combined[i];
		p_src = g_variables.list[i].key;
		while (*p_src != '\0')
			*p_combined++ = *p_src++;
		*p_combined++ = '=';
		p_src = g_variables.list[i].value;
		while (*p_src != '\0')
			*p_combined++ = *p_src++;
		*p_combined = '\0';
		++i;
	}
	pa_combined[i] = NULL;
	return (pa_combined);
}

void	destroy_envs(char **envs)
{
	char	**p_envs;

	p_envs = envs;
	while (*p_envs != NULL)
	{
		free(*p_envs);
		++p_envs;
	}
	free(envs);
}
