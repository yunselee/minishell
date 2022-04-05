/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_variable.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:30:08 by seunghyk          #+#    #+#             */
/*   Updated: 2022/04/05 18:29:34 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char				*get_env_variable_or_null(const char *key);
void				register_env_variable(const char *key,
						const char *value_or_null);
void				remove_env_variable(const char *key);
char				**get_all_env_malloc(void);
void				destroy_envs(char **envs);
t_env_variable_list	*get_env_list(void);

#endif /* ENV_VARIABLE_H */
