#include <stdlib.h>
#include "env_variable.h"

static t_env_variable_list g_variables;

static int index_of_env(const char* key)
{
	int	index;

	index = 0;
	while (index < g_variables.size)
	{
		if (ft_strncmp(key, g_variables.list[index].key, MAX_KEY_LENGTH) == 0)
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
	return (g_variables.list[index].value);
}

void register_env_variable(const char* key, const char* value_or_null)
{
	t_env_variable	*new_env;
	int				index;

	index = index_of_env(key);
	if (index == -1)
	{
		new_env = &g_variables.list[g_variables.size++];
		ft_strlcpy(new_env->key, key, MAX_KEY_LENGTH)
	}
	else
	{
		new_env = &g_variables.list[index];
	}
	if (value_or_null == NULL)
	{
		new_env->value[0] = '\0';
	}
	else
	{
		ft_strlcpy(new_env->value, value, MAX_VALUE_LENGTH);
	}
}

void remove_env_variable(const char* key)
{
	t_env_variable	*del_env;
	int				index;

	index = index_of_env(key);
	if (index != -1)
	{
		g_variables.list[index] = g_variables.list[--g_variables.size];
	}
}
