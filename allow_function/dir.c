/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:46:06 by yunselee          #+#    #+#             */
/*   Updated: 2022/03/17 21:14:44 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>

DIR	*_opendir(const char *name)
{
	DIR	*ret = opendir(name);

	if (ret == NULL)
	{
		printf("%s\n", strerror(errno));
		exit(1);
	}
	return (ret);
}

struct dirent	*_readdir(DIR *dirp)
{
	struct dirent	*ret = readdir(dirp);

	if (ret == NULL)
	{
		printf("%s\n", strerror(errno));
		exit(1);
	}
	return (ret);
}

int	_closedir(DIR *dirp)
{
	const int	ret = closedir(dirp);

	if (ret == -1)
	{
		printf("%s\n", strerror(errno));
		exit(1);
	}
	return (ret);
}
