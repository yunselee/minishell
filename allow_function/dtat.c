/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:45:41 by yunselee          #+#    #+#             */
/*   Updated: 2022/03/17 21:16:10 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdlib.h>

int	_stat(const char *pathname, struct stat *statbuf)
{
	const int	ret = stat(pathname, statbuf);

	if (ret == -1)
	{
		printf("%s\n", strerror(errno));
		exit(1);
	}
	return (ret);
}

int	_fstat(int fd, struct stat *statbuf)
{
	const int	ret = fstat(fd, statbuf);

	if (ret == -1)
	{
		printf("%s\n", strerror(errno));
		exit(1);
	}
	return (ret);
}

int	_lstat(const char *pathname, struct stat *statbuf)
{
	const int	ret = lstat(pathname, statbuf);

	if (ret == -1)
	{
		printf("%s\n", strerror(errno));
		exit(1);
	}
	return (ret);
}
