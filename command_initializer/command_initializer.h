#ifndef COMMAND_INITIALIZER_H
# define COMMAND_INITIALIZER_H

# define MAX_TOKEN_LENGTH (512)
# define MAX_TOKEN_COUNT (512)

# include <stdbool.h>

typedef struct s_command
{
	char tokens[MAX_TOKEN_COUNT][MAX_TOKEN_LENGTH];
	int num_token;
}				t_command;

bool	try_init_command(char *text, t_command *out_command);
void	tokenize_command(char *text, t_command *out_command);
void	reinterpret_env(char *token);
void	reinterpret_escape(char *token, bool is_plain);

#endif /* COMMAND_INITIALIZER_H */