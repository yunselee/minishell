/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:45:36 by yunselee          #+#    #+#             */
/*   Updated: 2022/03/24 17:17:05 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

pid_t	_wait(int *wstatus)
{
	const pid_t	ret = wait(wstatus);

	if (ret == -1)
	{
		printf("%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	return (ret);
}

pid_t _waitpid(pid_t pid, int *status, int options)
{
	const pid_t	ret = waitpid(pid, status, options);

	if (ret == -1)
	{
		printf("%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	return (ret);

}

