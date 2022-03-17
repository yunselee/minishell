#ifndef ENV_VARIABLE_H
# define ENV_VARIABLE_H

typedef struct s_env_variable
{
	const char	*key;
	const char	*value;
}				t_env_variable;

typedef struct s_env_variable_list
{
	t_env_variable	list[MAX_ENV];
	int				size;
}				t_env_variable_list;

const char*	get_env_variable_or_null(const char *key);
void		register_env_variable(const char *key, const char *value);
void		remove_env_variable(const char *key);
void		destory_env_variable(void);

#endif /* ENV_VARIABLE_H */
