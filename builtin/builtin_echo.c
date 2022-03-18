/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:04:06 by yunselee          #+#    #+#             */
/*   Updated: 2022/03/18 18:34:56 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exit_code.h"
#include "builtin.h"
#include <stdio.h>
#include <stdbool.h>
#define ARG_NEWLINE "-n"

void	builtin_echo(const char **tokens, int token_size)
{
	bool	is_newline;
	int		i;

	i = 0;
	is_newline = true;
	if (i < is_newline && strcmp(tokens[i], ARG_NEWLINE) == 0)
	{
		is_newline = false;
		i++;
	}
	while (i < token_size - 1)
	{
		printf("%s ", tokens[i]);
		i++;
	}
	printf("%s", tokens[i]);
	if (is_newline)
		printf("\n");
}
