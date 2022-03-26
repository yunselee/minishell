/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:04:06 by yunselee          #+#    #+#             */
/*   Updated: 2022/03/26 16:02:43 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit_code.h"
#include "builtin.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define ARG_NEWLINE "-n"

void	builtin_echo(const char **args)
{
	bool	is_newline;
	int		exit_code;
	int		i;

	i = 1;
	is_newline = true;
	if (i < is_newline && strcmp(args[i], ARG_NEWLINE) == 0)
	{
		is_newline = false;
		i++;
	}
	while (args[i] != NULL)
	{
		printf("%s ", args[i]);
		i++;
	}
	printf("%s", args[i]);
	if (is_newline)
		printf("\n");
	exit_code_set(EXIT_SUCCESS);
}
