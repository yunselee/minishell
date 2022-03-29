/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_variable_destroy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghyk <seunghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:30:02 by seunghyk          #+#    #+#             */
/*   Updated: 2022/03/29 19:30:12 by seunghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "env_variable.h"

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
