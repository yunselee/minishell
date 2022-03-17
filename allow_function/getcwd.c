/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:46:00 by yunselee          #+#    #+#             */
/*   Updated: 2022/03/17 21:20:52 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*_getcwd(char *buf, size_t size)
{
	char	*ret;

	ret = getcwd(buf, size);
	if (ret == NULL)
	{
		printf("%s\n", strerror(errno));
		exit(1);
	}
	return (ret);
}
