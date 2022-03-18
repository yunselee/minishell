/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:18:43 by yunselee          #+#    #+#             */
/*   Updated: 2022/03/18 19:24:20 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	builtin_unset(const char **tokens, int token_size)
{
	int	i;

	i = 0;
	while (i < token_size)
	{
		remove_env_variable(tokens[i]);
		i++;
	}
}
