/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:51:35 by yunselee          #+#    #+#             */
/*   Updated: 2022/04/05 13:35:57 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sig.h"
#include <stdio.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

extern void	rl_replace_line(const char *a, int b);

static void	sig_int(int signal)
{
	(void)signal;
	rl_on_new_line();
	rl_redisplay();
	printf("%c[K\n", 27);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	sig_set(void)
{
	signal(SIGINT, sig_int);
	signal(SIGQUIT, SIG_IGN);
}

void	sig_disable(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}
