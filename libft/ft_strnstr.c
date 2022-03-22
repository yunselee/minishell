/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 19:27:07 by yunselee          #+#    #+#             */
/*   Updated: 2022/01/24 13:43:08 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	i = 0;
	little_len = ft_strlen(little);
	if (little_len == 0)
	{
		return ((char *)big);
	}
	while (big[i] && i + little_len <= len)
	{
		if (ft_strncmp(big + i, little, little_len) == 0)
		{
			return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
