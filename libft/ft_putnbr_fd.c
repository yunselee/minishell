/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 22:46:29 by yunselee          #+#    #+#             */
/*   Updated: 2022/01/24 13:40:09 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	cchar[11];
	int		i;

	i = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	while (i < 10)
	{
		cchar[i] = i + '0';
		i++;
	}
	cchar[10] = '-';
	if (n < 0)
	{
		write(fd, cchar + 10, 1);
		n *= -1;
	}
	if (n / 10 != 0)
		ft_putnbr_fd(n / 10, fd);
	write(fd, cchar + n % 10, 1);
}
