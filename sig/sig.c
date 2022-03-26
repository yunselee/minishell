/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:51:35 by yunselee          #+#    #+#             */
/*   Updated: 2022/03/26 21:04:31 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sig.h"
#include <stdio.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

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

static void sig_quit(int siganl)
{
	(void)siganl;
	exit(0);
}

void	sig_set(void)
{
	signal(SIGINT, sig_int);
	signal(SIGQUIT, SIG_IGN);
}

void	sig_disable(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, sig_quit);
}
