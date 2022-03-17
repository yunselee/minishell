#include "env_variable.h"

#define MAX_ENV (1024)

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

static t_env_variable_list g_variables;

static int index_of_env(const char* key)
{
	int	index;

	index = 0;
	while (index < g_variables.size)
	{
		if (ft_strcmp(key, g_variables.list[index]->key) == 0)
		{
			return (index);
		}
		++index;
	}
	return (-1);
}

const char* get_env_variable_or_null(const char* key)
{
	size_t	index;

	index = index_of_env(key);
	if (index == -1)
	{
		return (NULL);
	}
	return (g_variables.list[index]->value);
}

void register_env_variable(const char* key, const char* value)
{
	t_env_variable	*new_env;
	int				index;

	index = index_of_env(key);
	if (index == -1)
	{
		new_env = &g_variables.list[g_variables.size++];
	}
	else
	{
		new_env = &g_variables.list[index];
		free(env->key);
		free(env->value)
	}
	new_env->key = key;
	new_env->value = value;
}

void remove_env_variable(const char* key)
{
	t_env_variable	*del_env;
	int				index;

	index = index_of_env(key);
	if (index == -1)
	{
		return;
	}
	del_env = &g_variables.list[index];
	free(del_env->key);
	free(del_env->value);
	g_variables.list[index] = g_variables.list[--g_variables.size];
}

void destory_env_variable(void)
{
	int index;

	index = 0;
	while (index < g_variables.size)
	{
		free(g_variables.list[index]->key);
		free(g_variables.list[index]->value);
		++index;
	}
}
