/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 17:30:03 by yunselee          #+#    #+#             */
/*   Updated: 2022/03/18 17:48:08 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


static unsigned char	*getter(void)
{
	static unsigned char	exit_code;

	return (&exit_code);
}

int	get_recent_exit_code(void)
{
	return (*getter());
}

void	set_exit_code(int code)
{
	*getter() = code;
}
