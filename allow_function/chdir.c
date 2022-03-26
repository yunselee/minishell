/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chdir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:46:10 by yunselee          #+#    #+#             */
/*   Updated: 2022/03/26 16:03:07 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	_chdir(const char *path)
{
	const int	ret = chdir(path);

	if (ret == -1)
	{
		printf("%s\n", strerror(errno));
	}
	return (ret);
}
