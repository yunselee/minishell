/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:03:30 by yunselee          #+#    #+#             */
/*   Updated: 2022/03/26 17:21:07 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../exit_code/exit_code.h"
#include "builtin.h"
#include "../env_variable/env_variable.h"
#include "../libft/libft.h"

static char	*tokenize(char *str_or_null, const char *delims)
{
	static char	*s_str = NULL;
	char		*token;

	if (str_or_null != NULL)
		s_str = str_or_null;
	else if (s_str == NULL)
		return (NULL);
	while (*s_str != '\0' && ft_strchr(delims, *s_str) != NULL)
		++s_str;
	token = s_str;
	while (*s_str != '\0' && ft_strchr(delims, *s_str) == NULL)
		++s_str;
	if (*s_str == '\0')
		s_str = NULL;
	else
		*s_str++ = '\0';
	if (*token == '\0')
		return (NULL);
	return (token);
}

void	builtin_export(char **args)
{
	char	*key;
	char	*value;
	int			i;

	i = 1;
	while (args[i] != NULL)
	{
		key = tokenize(args[i], "=");
		value = tokenize(NULL, "=");
		register_env_variable(key, value);
		i++;
	}
	exit_code_set(EXIT_SUCCESS);
}
