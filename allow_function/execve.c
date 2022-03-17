/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:27:20 by yunselee          #+#    #+#             */
/*   Updated: 2022/03/17 21:14:57 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	_execve(const char *pathname, char *const argv[], char *const envp[])
{
	const int	ret = execve(pathname, argv, envp);

	if (ret == -1)
	{
		printf("%s\n", strerror(errno));
		exit(1);
	}
	return (ret);
}
