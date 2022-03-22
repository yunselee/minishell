#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "command_initializer.h"
#include "../libft/libft.h"

static bool is_open_quot(const char *text)
{
	const char	*p_text;
	char		quot;

	quot = 0;
	p_text = text;
	while (*p_text != '\0')
	{
		if (quot == 0 && (*p_text == '\"' || *p_text == '\''))
			quot = *p_text;
		else if (quot == *p_text)
			quot = 0;
		p_text++;
	}
	if (quot != 0)
		return (true);
	return (false);
}

static bool is_empty_line(const char* text)
{
	const char* p_text;

	p_text = text;
	while (*p_text != '\0')
	{
		if (*p_text != ' ' && *p_text != '\t')
			return (false);
		p_text++;
	}
	return (true);
}

bool try_init_command(char *text, t_command *out_command)
{
	out_command->num_token = 0;
	if (is_empty_line(text))
	{
		return (false);
	}
	add_history(text);
	if (is_open_quot(text))
	{
		printf("Invalide Syntax\n");
		return (false);
	}
	tokenize_command(text, out_command);
	return true;
}
