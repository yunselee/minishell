/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:49:57 by yunselee          #+#    #+#             */
/*   Updated: 2022/03/18 18:34:59 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../env_variable/env_variable.h"
#include <stdio.h>

void	builtin_env(void)
{
	const t_env_variable_list	*all_env = get_all_env();
	int							i;

	i = 0;
	while (i < all_env->size)
	{
		printf("%s=%s\n", all_env->list[i].key, all_env->list[i].value);
		i++;
	}
}
