/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:52:24 by yunselee          #+#    #+#             */
/*   Updated: 2022/03/31 17:46:33 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include <stdlib.h>
#include "libft.h"
#include <stdbool.h>

static bool	try_atoi(char *str, int *out_num)
{
	int	num;

	num = ft_atoi(str);
	num = num & 0x000000FF;
	*out_num = num;
	return (true);
}

// no return
void	builtin_exit(const char **args)
{
	int	exit_code;

	if (args[1] != NULL && args[2] != NULL)
	{
		printf("minishell : exit: too many arguments\n");
		exit(1);
	}
	if (args[1] == NULL)
		exit(0);
	if (try_atoi(args[1], &exit_code))
	{
		printf("exit\n");
		exit(exit_code);
	}
	else
	{
		printf("exit: $s: numeric argument required\n", args[1]);
		exit(255);
	}
}
