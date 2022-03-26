/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:49:57 by yunselee          #+#    #+#             */
/*   Updated: 2022/03/26 16:00:34 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../env_variable/env_variable.h"
#include <stdio.h>
#include <stdlib.h>

void	builtin_env(void)
{
	const char	**all_env = get_all_env();
	int							i;

	i = 0;
	while (i < all_env)
	{
		printf("%s\n", all_env[i]);
		i++;
	}
	exit_code_set(EXIT_SUCCESS);
}
