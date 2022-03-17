/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:48:57 by yunselee          #+#    #+#             */
/*   Updated: 2022/01/24 13:38:13 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current_list;
	t_list	*next_list;

	current_list = *lst;
	while (current_list != NULL)
	{
		next_list = current_list->next;
		ft_lstdelone(current_list, del);
		current_list = next_list;
	}
	*lst = NULL;
}
