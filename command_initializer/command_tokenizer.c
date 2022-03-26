#include <stdlib.h>
#include "command_initializer.h"
#include "../libft/libft.h"

static char *init_plain_command(char *text, t_command *out_command)
{
	char	*p_token;
	char	*p_end;

	p_token = out_command->tokens[out_command->num_token++];
	p_end = text;
	while (ft_strchr("\"\'><| \t", *p_end) == NULL)
		p_end++;
	ft_strlcpy(p_token, text, p_end - text + 1);
	reinterpret_env(p_token);
	return (p_end - 1);
}

static char *init_redirection_command(char *text, t_command *out_command)
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

static char *init_single_quot_command(char *text, t_command *out_command)
{
	char	*p_token;
	char	*p_end;

	text++;
	p_token = out_command->tokens[out_command->num_token++];
	p_end = ft_strchr(text, '\'');
	ft_strlcpy(p_token, text, p_end - text + 1);
	reinterpret_escape(p_token);
	return (p_end);
}

static char *init_double_quot_command(char *text, t_command *out_command)
{
	char	*p_token;
	char	*p_end;

	text++;
	p_token = out_command->tokens[out_command->num_token++];
	p_end = ft_strchr(text, '\"');
	ft_strlcpy(p_token, text, p_end - text + 1);
	reinterpret_env(p_token);
	reinterpret_escape(p_token);
	return (p_end);
}

void tokenize_command(char *text, t_command *out_command)
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
		else if (*p_text != ' ' && *p_text != '\t')
		{
			p_text = init_plain_command(p_text, out_command);
		}
		p_text++;
	}
}