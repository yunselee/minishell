/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_exe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:12:58 by yunselee          #+#    #+#             */
/*   Updated: 2022/04/05 18:29:53 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include "sig.h"
#include <stdlib.h>
#include <readline/readline.h>
#include <unistd.h>

extern void	rl_replace_line(const char *a, int b);
#define HEREDOC_PROMPT "\e[32m> \e[0m"

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

static void	sig_int_heredoc(int signal)
{
	(void)signal;
	printf("%s%c[K\n", HEREDOC_PROMPT, 27);
	exit(EXIT_FAILURE);
}

void	sig_set_heredoc(void)
{
	signal(SIGINT, sig_int_heredoc);
	signal(SIGQUIT, SIG_IGN);
}
