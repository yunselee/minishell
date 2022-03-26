/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:39:24 by yunselee          #+#    #+#             */
/*   Updated: 2022/03/24 17:14:44 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../allow_function/allow_function.h"
#include <stdlib.h>

void	builtin_pwd(void)
{
	const char	*pwd = _getcwd(NULL, 512);

	if (pwd == NULL)
	{
		exit_code_set(EXIT_FAILURE);
		return ;
	}
	printf("%s", pwd);
	free(pwd);
	exit_code_set(EXIT_SUCCESS);
}
