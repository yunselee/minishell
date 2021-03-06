/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghyk <seunghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 19:27:20 by yunselee          #+#    #+#             */
/*   Updated: 2022/03/29 19:00:25 by seunghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	_execve(const char *pathname, char *const argv[], char *const envp[])
{
	const int	ret = execve(pathname, argv, envp);

	return (ret);
}
