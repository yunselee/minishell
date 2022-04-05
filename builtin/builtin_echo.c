/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:04:06 by yunselee          #+#    #+#             */
/*   Updated: 2022/04/05 19:08:58 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../exit_code/exit_code.h"
#include "builtin.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../libft/libft.h"

#define ARG "n"

static bool	in_arg(const char *str, const char *arg)
{
	int	i;

	i = 1;
	while (str[i] != '\0')
	{
		if (ft_strrchr(arg, str[i]) == NULL)
			return (false);
		i++;
	}
	return (true);
}

void	builtin_echo(const char **args)
{
	bool	is_newline;
	int		i;

	i = 1;
	is_newline = true;
	while (args[i] != NULL && args[i][0] == '-')
	{
		if (in_arg(args[i], ARG))
			is_newline = false;
		i++;
	}
	while (args[i] != NULL)
	{
		printf("%s ", args[i]);
		i++;
	}
	if (is_newline)
		printf("\n");
	exit_code_set(EXIT_SUCCESS);
}
