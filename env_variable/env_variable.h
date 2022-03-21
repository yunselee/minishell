#ifndef ENV_VARIABLE_H
# define ENV_VARIABLE_H

# define MAX_ENV (512)
# define MAX_KEY_LENGTH (256)
# define MAX_VALUE_LENGTH (256)

typedef struct s_env_variable
{
	char	key[MAX_KEY_LENGTH];
	char	value[MAX_VALUE_LENGTH];
}				t_env_variable;

typedef struct s_env_variable_list
{
	t_env_variable	list[MAX_ENV];
	int				size;
}				t_env_variable_list;

const char*	get_env_variable_or_null(const char *key);
void		register_env_variable(const char *key, const char *value_or_null);
void		remove_env_variable(const char *key);

#endif /* ENV_VARIABLE_H */
