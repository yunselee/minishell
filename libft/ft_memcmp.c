/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:54:02 by yunselee          #+#    #+#             */
/*   Updated: 2022/01/24 13:39:29 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1c;
	const unsigned char	*s2c;
	size_t				i;

	i = 0;
	s1c = (unsigned char *)s1;
	s2c = (unsigned char *)s2;
	while (i < n && *(s1c + i) == *(s2c + i))
		i++;
	if (i == n)
		return (0);
	return (*(s1c + i) - *(s2c + i));
}
