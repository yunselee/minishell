/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:30:03 by yunselee          #+#    #+#             */
/*   Updated: 2022/03/23 16:32:52 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit_code.h"

static unsigned char	*getter(void)
{
	static unsigned char	exit_code;

	return (&exit_code);
}

int		exit_code_get_latest (void)
{
	return (*getter());
}

void	exit_code_set(int code)
{
	*getter() = code;
}
