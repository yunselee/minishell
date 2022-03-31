#include <stdlib.h>
#include "../libft/libft.h"

static int	partition(char **envs, int left, int right)
{
	char	*pivotKey;
	int		pivotPos;
	int		i;
	char	*temp;

	pivotKey = envs[right];
	pivotPos = left;
	i = left;
	while (i < right)
	{
		if (0 < ft_strcmp(pivotKey, envs[i]))
		{
			temp = envs[pivotPos];
			envs[pivotPos] = envs[i];
			envs[i] = temp;
			++pivotPos;
		}
		++i;
	}
	return (pivotPos);
}

static void	sort_recursive(char **envs, int left, int right)
{
	char	*temp;
	int		pivot;

	if (right <= left)
	{
		return ;
	}
	pivot = partition(envs, left, right);
	temp = envs[pivot];
	envs[pivot] = envs[right];
	envs[right] = temp;
	sort_recursive(envs, left, pivot - 1);
	sort_recursive(envs, pivot + 1, right);
}

void	sort(char **envs)
{
	char	**p_envs;
	int		n;

	p_envs = envs;
	n = 0;
	while (*p_envs != NULL)
	{
		++n;
		++p_envs;
	}
	sort_recursive(envs, 0, n - 1);
}

char	*tokenize(char *str_or_null, const char *delims)
{
	static char	*s_str = NULL;
	char		*token;

	if (str_or_null != NULL)
		s_str = str_or_null;
	else if (s_str == NULL)
		return (NULL);
	while (*s_str != '\0' && ft_strchr(delims, *s_str) != NULL)
		++s_str;
	token = s_str;
	while (*s_str != '\0' && ft_strchr(delims, *s_str) == NULL)
		++s_str;
	if (*s_str == '\0')
		s_str = NULL;
	else
		*s_str++ = '\0';
	if (*token == '\0')
		return (NULL);
	return (token);
}
