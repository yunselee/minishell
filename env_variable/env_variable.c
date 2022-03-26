#include <stdlib.h>
#include "../libft/libft.h"
#include "env_variable.h"

static t_env_variable_list g_variables;

static int index_of_env(const char *key)
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
	int	index;

	index = index_of_env(key);
	if (index == -1)
	{
		return (NULL);
	}
	return (g_variables.list[index].value);
}

void register_env_variable(const char *key, const char *value_or_null)
{
	t_env_variable	*new_env;
	int				index;

	index = index_of_env(key);
	if (index == -1)
	{
		new_env = &g_variables.list[g_variables.size++];
		ft_strlcpy(new_env->key, key, MAX_KEY_LENGTH);
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
		ft_strlcpy(new_env->value, value_or_null, MAX_VALUE_LENGTH);
	}
}

void remove_env_variable(const char *key)
{
	int				index;

	index = index_of_env(key);
	if (index != -1)
	{
		g_variables.list[index] = g_variables.list[--g_variables.size];
	}
}

char	**get_all_env_malloc(void)
{
	char	**pa_combined;
	char	*p_combined;
	char	*p_src;
	int		i;

	i = 0;
	pa_combined = (char**)malloc(sizeof(char*) * (MAX_ENV + 1));
	while (i < g_variables.size)
	{
		pa_combined[i] = (char*)malloc(sizeof(char) * (MAX_KEY_LENGTH + MAX_VALUE_LENGTH));
		p_combined = pa_combined[i];
		p_src = g_variables.list[i].key;
		while (*p_src != '\0')
			*p_combined++ = *p_src++;
		*p_combined++ = '=';
		p_src = g_variables.list[i].value;
		while (*p_src != '\0')
			*p_combined++ = *p_src++;
		*p_combined = '\0';
		++i;
	}
	pa_combined[i] = NULL;
	return (pa_combined);
}

void	destroy_envs(char **envs)
{
	char **p_envs;

	p_envs = envs;
	while (*p_envs != NULL)
	{
		free(*p_envs);
		++p_envs;
	}
	free(envs);
}
