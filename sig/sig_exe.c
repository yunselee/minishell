/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_child.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:12:58 by yunselee          #+#    #+#             */
/*   Updated: 2022/03/31 22:23:55 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include "sig.h"
#include <stdlib.h>

static void	sig_int_execve(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
	}
	if (signal == SIGQUIT)
	{
		printf("Quit: 3\n");
	}
}

void	sig_set_execve(void)
{
	signal(SIGINT, sig_int_execve);
	signal(SIGQUIT, sig_int_execve);
}
