/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghyk <seunghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:49:57 by yunselee          #+#    #+#             */
/*   Updated: 2022/03/29 19:07:34 by seunghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../env_variable/env_variable.h"
#include "../exit_code/exit_code.h"
#include <stdio.h>
#include <stdlib.h>

void	builtin_env(void)
{
	char	**all_env;
	int		i;

	all_env = get_all_env_malloc();
	i = 0;
	while (all_env[i] != NULL)
	{
		printf("%s\n", all_env[i]);
		i++;
	}
	destroy_envs(all_env);
	exit_code_set(EXIT_SUCCESS);
}
