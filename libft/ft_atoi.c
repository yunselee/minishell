/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 04:13:15 by yunselee          #+#    #+#             */
/*   Updated: 2022/01/24 13:23:45 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
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
	while (*str >= '0' && *str <= '9')
	{
		num *= 10;
		num += *str - '0';
		str++;
	}
	if (sign & 1)
		num *= -1;
	return (num);
}
