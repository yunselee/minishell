/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:50:53 by yunselee          #+#    #+#             */
/*   Updated: 2022/01/24 13:38:51 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret_lst;
	t_list	*temp;
	t_list	*now_lst;

	ret_lst = NULL;
	now_lst = lst;
	while (now_lst != NULL)
	{
		temp = ft_lstnew((*f)(now_lst->content));
		if (temp == NULL)
		{
			ft_lstclear(&ret_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&ret_lst, temp);
		now_lst = now_lst->next;
	}
	return (ret_lst);
}
