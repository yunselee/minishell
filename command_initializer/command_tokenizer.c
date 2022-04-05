/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_tokenizer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghyk <seunghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:29:58 by seunghyk          #+#    #+#             */
/*   Updated: 2022/04/05 19:27:29 by seunghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "command_initializer.h"
#include "../libft/libft.h"
#include <stdio.h>

static char	*init_plain_command(char *text, t_command *out_command)
{
	char	*p_token;
	char	*p_end;

	p_token = out_command->tokens[out_command->num_token++];
	p_end = text;
	while (*p_end != '\0')
	{
		if (*p_end == '\\' && (*(p_end + 1) == '\"' || *(p_end + 1) == '\''))
			p_end++;
		else if (*p_end == '\"' || *p_end == '\'' || *p_end == '>'
			|| *p_end == '<' || *p_end == '|' || *p_end == ' '
			|| *p_end == '\t' )
			break ;
		p_end++;
	}
	ft_strlcpy(p_token, text, p_end - text + 1);
	reinterpret_env(p_token);
	reinterpret_escape(p_token, true);
	return (p_end - 1);
}

static char	*init_redirection_command(char *text, t_command *out_command)
{
	char	*p_token;
	char	*p_end;

	p_token = out_command->tokens[out_command->num_token++];
	if (*text == *(text + 1))
		p_end = text + 2;
	else
		p_end = text + 1;
	ft_strlcpy(p_token, text, p_end - text + 1);
	return (p_end - 1);
}

static char	*init_single_quot_command(char *text, t_command *out_command)
{
	char	*p_token;
	char	*p_end;
	char	before;

	before = *(text - 1);
	text++;
	p_token = out_command->tokens[out_command->num_token++];
	p_end = ft_strchr(text, '\'');
	while (*(p_end - 1) == '\\')
	{
		p_end = ft_strchr(p_end + 1, '\'');
	}
	ft_strlcpy(p_token, text, p_end - text + 1);
	if (before == '\'' || before == '\"')
	{
		ft_strcat(out_command->tokens[out_command->num_token - 2],
			out_command->tokens[out_command->num_token - 1]);
		out_command->num_token--;
	}
	return (p_end);
}

static char	*init_double_quot_command(char *text, t_command *out_command)
{
	char	*p_token;
	char	*p_end;
	char	before;

	before = *(text - 1);
	text++;
	p_token = out_command->tokens[out_command->num_token++];
	p_end = ft_strchr(text, '\"');
	while (*(p_end - 1) == '\\')
	{
		p_end = ft_strchr(p_end + 1, '\"');
	}
	ft_strlcpy(p_token, text, p_end - text + 1);
	reinterpret_env(p_token);
	if (before == '\'' || before == '\"')
	{
		ft_strcat(out_command->tokens[out_command->num_token - 2],
			out_command->tokens[out_command->num_token - 1]);
		out_command->num_token--;
	}
	return (p_end);
}

void	tokenize_command(char *text, t_command *out_command)
{
	char	*p_text;

	p_text = text;
	while (*p_text != '\0')
	{
		if (*p_text == '\"')
		{
			p_text = init_double_quot_command(p_text, out_command);
		}
		else if (*p_text == '\'')
		{
			p_text = init_single_quot_command(p_text, out_command);
		}
		else if (*p_text == '>' || *p_text == '<' || *p_text == '|')
		{
			p_text = init_redirection_command(p_text, out_command);
		}
		else if ((*p_text != ' ' && *p_text != '\t') || *p_text == '\\')
		{
			p_text = init_plain_command(p_text, out_command);
		}
		p_text++;
	}
}
