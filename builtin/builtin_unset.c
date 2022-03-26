/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:18:43 by yunselee          #+#    #+#             */
/*   Updated: 2022/03/26 17:14:43 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exit_code/exit_code.h"
#include "builtin.h"
#include "../env_variable/env_variable.h"
#include <stdlib.h>

void	builtin_unset(const char **args)
{
	int	i;

	i = 1;
	while (args[i] != NULL)
	{
		remove_env_variable(args[i]);
		i++;
	}
	exit_code_set(EXIT_SUCCESS);
}
