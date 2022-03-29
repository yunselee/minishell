/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_reinterpreter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghyk <seunghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:29:56 by seunghyk          #+#    #+#             */
/*   Updated: 2022/03/29 19:30:12 by seunghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "command_initializer.h"
#include "../env_variable/env_variable.h"
#include "../libft/libft.h"

static char	get_escape(char c, bool is_plain)
{
	if (is_plain)
		return (c);
	if (c == 'n')
		return ('\n');
	else if (c == 't')
		return ('\t');
	else if (c == '\\')
		return ('\\');
	else if (c == '\r')
		return ('\r');
	else if (c == ' ')
		return ('\\');
	else if (c == '\t')
		return ('\\');
	else
		return (c);
}

void	reinterpret_env(char *token)
{
	char		copied[MAX_KEY_LENGTH];
	char		*p_end;
	char		*p_key;
	const char	*p_value;

	p_key = ft_strchr(token, '$');
	while (p_key != NULL)
	{
		p_end = p_key + 1;
		while (*p_end != ' ' && *p_end != '\t' && *p_end != '\0')
			p_end++;
		ft_strlcpy(copied, p_key + 1, p_end - p_key);
		p_value = get_env_variable_or_null(copied);
		if (p_value != NULL)
		{
			ft_strlcpy(copied, p_end, ft_strlen(p_end) + 1);
			while (*p_value != '\0')
				*p_key++ = *p_value++;
			ft_strlcpy(p_key, copied, ft_strlen(p_end) + 1);
		}
		else
			ft_strlcpy(p_key, p_end, ft_strlen(p_end) + 1);
		p_key = ft_strchr(token, '$');
	}
}

void	reinterpret_escape(char *token, bool is_plain)
{
	char	*p_escape;
	char	*p_end;
	char	c;

	p_escape = ft_strchr(token, '\\');
	while (p_escape != NULL)
	{
		c = *(p_escape + 1);
		if (c == '\0')
		{
			return ;
		}
		c = get_escape(*(p_escape + 1), is_plain);
		*p_escape++ = c;
		p_end = p_escape + 1;
		while (*p_end != '\0')
		{
			*p_escape++ = *p_end++;
		}
		*p_escape = '\0';
		p_escape = ft_strchr(token, '\\');
	}
}
