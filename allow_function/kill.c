/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Kill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:45:54 by yunselee          #+#    #+#             */
/*   Updated: 2022/03/17 21:15:14 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

typedef void	(*t_sighandler)(int);

int	_kill(pid_t pid, int sig)
{
	const int	ret = kill(pid, sig);

	if (ret == -1)
	{
		printf("%s\n", strerror(errno));
		exit(1);
	}
	return (ret);
}

t_sighandler	_signal(int signum, t_sighandler handler)
{
	const t_sighandler	ret = signal(signum, handler);

	if (ret == SIG_ERR)
	{
		printf("%s\n", strerror(errno));
		exit(1);
	}
	return (ret);
}
