/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghyk <seunghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:52:24 by yunselee          #+#    #+#             */
/*   Updated: 2022/03/31 18:26:47 by seunghyk         ###   ########.fr       */
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

// no return
void	builtin_exit(const char **args)
{
	int	exit_code;

	if (args[1] != NULL && args[2] != NULL)
	{
		printf("minishell: exit: too many arguments\n");
		exit(1);
	}
	if (args[1] == NULL)
		exit(0);
	if (try_get_exit_code(args[1], &exit_code))
	{
		printf("exit\n");
		exit(exit_code);
	}
	else
	{
		printf("minishell: exit: %s: numeric argument required\n", args[1]);
		exit(255);
	}
}
