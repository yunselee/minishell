/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghyk <seunghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:37:35 by yunselee          #+#    #+#             */
/*   Updated: 2022/03/29 19:06:56 by seunghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "env_variable.h"
#include <unistd.h>
#include "../allow_function/allow_function.h"
#include "../exit_code/exit_code.h"

#define HOME "HOME"
#define OLDPWD "OLDPWD" //=/Users/yunselee/minishell
#define PWD "PWD" //=/Users/yunselee/minishell/builtin

void	builtin_cd(const char **args)
{
	const char	*path = args[1];
	const char	*old_pwd;
	char		*cur_pwd;
	int			exit_code;

	if (path == NULL)
		path = get_env_variable_or_null(HOME);
	exit_code = _chdir(path);
	old_pwd = get_env_variable_or_null(PWD);
	cur_pwd = _getcwd(NULL, 0);
	register_env_variable(OLDPWD, old_pwd);
	register_env_variable(PWD, cur_pwd);
	_free((void *)cur_pwd);
	if (exit_code != 0)
		exit_code_set(1);
	else
	{
		exit_code_set(exit_code);
	}
}
