/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_child.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:12:58 by yunselee          #+#    #+#             */
/*   Updated: 2022/03/31 16:32:36 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>

static void	sig_int_child(int signal)
{
	(void)signal;
	exit(0);
}

void	sig_set_child(void)
{
	signal(SIGINT, sig_int_child);
}
