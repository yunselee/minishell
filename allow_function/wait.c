/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:45:36 by yunselee          #+#    #+#             */
/*   Updated: 2022/03/17 21:16:19 by yunselee         ###   ########.fr       */
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
		exit(1);
	}
	return (ret);
}
