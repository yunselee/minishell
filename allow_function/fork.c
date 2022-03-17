/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:46:02 by yunselee          #+#    #+#             */
/*   Updated: 2022/03/17 21:15:02 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pid_t	_fork(void)
{
	const pid_t	ret = fork();

	if (ret == -1)
	{
		printf("%s\n", strerror(errno));
		exit(1);
	}
	return (ret);
}
