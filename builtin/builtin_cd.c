/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:37:35 by yunselee          #+#    #+#             */
/*   Updated: 2022/03/18 18:57:24 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "../env_variable/env_variable.h"
#include <unistd.h>

#define HOME "HOME"
#define OLDPWD "OLDPWD" //=/Users/yunselee/minishell
#define PWD "PWD" //=/Users/yunselee/minishell/builtin

void	builtin_cd(const char **tokens, int token_size)
{
	const char	*path = tokens[0];
	const char	*a;
	const char	*old_pwd;
	const char	*cur_pwd;

	if (token_size > 1)
	{
		printf("%s", "cd: string not in pwd: ", tokens[0]);
		exit (1);
	}
	if (token_size == 0)
		path = get_env_variable_or_null(HOME);
	_chdir(path);
	old_pwd = get_env_variable_or_null(PWD);
	cur_pwd = getcwd(NULL, 0);
	register_env_variable(OLDPWD, old_pwd);
	register_env_variable(PWD, cur_pwd);
	free(cur_pwd);
}
