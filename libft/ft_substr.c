/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 18:11:08 by yunselee          #+#    #+#             */
/*   Updated: 2022/01/24 13:44:20 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	len_from_start;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	len_from_start = ft_strlen(s + start);
	if (len_from_start < len)
		len = len_from_start;
	substr = (char *)ft_calloc(1, sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
