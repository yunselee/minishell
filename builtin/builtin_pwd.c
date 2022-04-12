/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:39:24 by yunselee          #+#    #+#             */
/*   Updated: 2022/04/10 20:11:41 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "allow_function.h"
#include <stdlib.h>
#include "exit_code.h"
#include <stdio.h>

void	builtin_pwd(void)
{
	char	*pwd;

	pwd = _getcwd(NULL, 512);
	if (pwd == NULL)
	{
		exit_code_set(EXIT_FAILURE);
		return ;
	}
	printf("%s\n", pwd);
	_free((void *)pwd);
	exit_code_set(EXIT_SUCCESS);
}
