/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:45:57 by yunselee          #+#    #+#             */
/*   Updated: 2022/03/17 21:15:38 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

void	*_malloc(unsigned int size)
{
	void	*pointer;

	pointer = malloc(size);
	if (pointer == NULL)
	{
		printf("%s\n", strerror(errno));
		exit(1);
	}
	return (pointer);
}

void	_free(void *pointer)
{
	free(pointer);
}
