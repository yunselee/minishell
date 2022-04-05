/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghyk <seunghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:49:57 by yunselee          #+#    #+#             */
/*   Updated: 2022/04/05 16:42:06 by seunghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../env_variable/env_variable.h"
#include "../exit_code/exit_code.h"
#include <stdio.h>
#include <stdlib.h>

void	builtin_env(void)
{
	t_env_variable_list	*variables;
	int					i;

	variables = get_env_list();
	i = 0;
	while (i < variables->size)
	{
		if (*(variables->list[i].value) != '\0')
		{
			printf("%s=%s\n", variables->list[i].key,
				variables->list[i].value);
		}
		++i;
	}
	exit_code_set(EXIT_SUCCESS);
}
