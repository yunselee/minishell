/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Unlink.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:45:32 by yunselee          #+#    #+#             */
/*   Updated: 2022/03/17 21:16:15 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int	_unlink(const char *pathname)
{
	const int	ret = unlink(pathname);

	if (ret == -1)
	{
		printf("%s\n", strerror(errno));
		exit(1);
	}
	return (ret);
}
