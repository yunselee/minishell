/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:04:06 by yunselee          #+#    #+#             */
/*   Updated: 2022/04/10 18:09:25 by yunselee         ###   ########.fr       */
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
	bool	is_arg;

	i = 1;
	is_newline = true;
	is_arg = true;
	while (is_arg && args[i] != NULL && args[i][0] == '-')
	{
		if (in_arg(args[i], ARG))
		{
			is_newline = false;
			i++;
		}
		else
			is_arg = false;
	}
	while (args[i] != NULL && printf("%s", args[i]) && i++)
	{
		if (args[i] != NULL)
			printf(" ");
	}
	if (is_newline)
		printf("\n");
	exit_code_set(EXIT_SUCCESS);
}
