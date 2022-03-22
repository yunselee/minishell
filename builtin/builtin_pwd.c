/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 14:39:24 by yunselee          #+#    #+#             */
/*   Updated: 2022/03/18 19:06:22 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../allow_function/allow_function.h"
#include <stdlib.h>

void	builtin_pwd(void)
{
	const char	*pwd = _getcwd(NULL, 0);

	printf("%s", pwd);
}
