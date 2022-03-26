/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:45:51 by yunselee          #+#    #+#             */
/*   Updated: 2022/03/24 17:00:41 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int				_open(const char *pathname, int flags, int mode)
{
	const int	ret = open(pathname, flags, mode);

	if (ret == -1)
	{
		printf("%s\n", strerror(errno));
	}
	return (ret);
}

int	_close(int fd)
{
	const int	ret = close(fd);

	if (ret == -1)
	{
		printf("%s\n", strerror(errno));
		exit(1);
	}
	return (ret);
}
