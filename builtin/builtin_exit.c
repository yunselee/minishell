/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:52:24 by yunselee          #+#    #+#             */
/*   Updated: 2022/04/02 15:59:28 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include <stdbool.h>
#include <limits.h>

static bool	try_atoi2(const char *str, long long *p_out_num)
{
	long long	overflow;
	long long	num;

	overflow = 0;
	num = 0;
	while (ft_isdigit(*str))
	{
		overflow *= 10;
		overflow += *str - '0';
		if (overflow < num)
			return (false);
		num = overflow;
		str++;
	}
	if (*str != '\0')
		return (false);
	*p_out_num = num;
	return (true);
}

static bool	try_atoi(const char *str, long long *p_out_num)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign++;
		str++;
	}
	if (!try_atoi2(str, &num))
	{
		return (false);
	}
	if (sign & 1)
		num *= -1;
	*p_out_num = num;
	return (true);
}

static bool	try_get_exit_code(const char *str, int *out_num)
{
	long long	num;

	if (!try_atoi(str, &num))
		return (false);
	num = num & 0x000000FF;
	*out_num = (int)num;
	return (true);
}

void	builtin_exit(const char **args)
{
	int	exit_code;

	printf("exit\n");
	if (args[1] == NULL)
		exit(0);
	if (try_get_exit_code(args[1], &exit_code))
	{
		if (args[1] != NULL && args[2] != NULL)
		{
			printf("minishell: %s: too many arguments\n", args[0]);
			return ;
		}
		exit(exit_code);
	}
	else
	{
		printf("minishell: %s: %s: numeric argument required\n", \
			args[0], args[1]);
		exit(255);
	}
}
