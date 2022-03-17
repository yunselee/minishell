/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:45:44 by yunselee          #+#    #+#             */
/*   Updated: 2022/03/17 21:15:58 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

ssize_t	_read(int fd, void*buf, size_t count)
{
	const ssize_t	ret = read(fd, buf, count);

	if (ret == -1)
	{
		printf("%s\n", strerror(errno));
		exit(1);
	}
	return (ret);
}
