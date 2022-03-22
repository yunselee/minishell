/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 20:35:53 by yunselee          #+#    #+#             */
/*   Updated: 2022/01/24 13:41:42 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(char const *s, char c)
{
	int	size;
	int	j;

	j = 0;
	size = 0;
	while (s[j] != '\0')
	{
		if (s[j] != c)
		{
			size++;
			while (s[j] != c && s[j] != '\0')
				j++;
		}
		while (s[j] == c && s[j] != '\0')
			j++;
	}
	return (size);
}

static char	*ret_str(char const *s, char c)
{
	int		i;
	char	*addr;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	addr = (char *)malloc(sizeof(char) * (i + 1));
	if (addr == NULL)
		return (NULL);
	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		addr[i] = s[i];
		i++;
	}
	addr[i] = '\0';
	return (addr);
}

static void	*free_split(char **split, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		size;
	char	**addr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size = get_size(s, c);
	addr = (char **)malloc(sizeof(char *) * (size + 1));
	if (addr == NULL)
		return (NULL);
	while (i < size)
	{
		while (s[j] == c)
			j++;
		addr[i] = ret_str(s + j, c);
		if (addr[i] == NULL)
			return (free_split(addr, i + 1));
		while (s[j] != c && s[j] != '\0')
			j++;
		i++;
	}
	addr[size] = NULL;
	return (addr);
}
