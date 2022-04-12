/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_tree.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunselee <yunselee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:29:30 by seunghyk          #+#    #+#             */
/*   Updated: 2022/04/10 20:10:05 by yunselee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>

#include "libft.h"
#include "as_tree.h"
#include <stdio.h>

static t_cmd_type	set_before(t_cmd_type *out_before, t_cmd_type cur_type)
{
	if (cur_type == CMD_TYPE_ARG && CMD_TYPE_L_SHIFT <= *out_before)
		*out_before = CMD_TYPE_NONE;
	else
		*out_before = cur_type;
	return (cur_type);
}

static t_cmd_type	get_cmd_type(char *data)
{
	static t_cmd_type	before = CMD_TYPE_NONE;
	static bool			is_command = true;
	t_cmd_type			type;

	if (ft_strcmp(data, ">") == 0)
		type = CMD_TYPE_R_SHIFT;
	else if (ft_strcmp(data, ">>") == 0)
		type = CMD_TYPE_RD_SHIFT;
	else if (ft_strcmp(data, "<") == 0)
		type = CMD_TYPE_L_SHIFT;
	else if (ft_strcmp(data, "<<") == 0)
		type = CMD_TYPE_LD_SHIFT;
	else if (ft_strcmp(data, "|") == 0)
	{
		type = CMD_TYPE_PIPE;
		is_command = true;
	}
	else if (is_command && (before == CMD_TYPE_NONE || before == CMD_TYPE_PIPE))
	{
		type = CMD_TYPE_COMMAND;
		is_command = false;
	}
	else
		type = CMD_TYPE_ARG;
	return (set_before(&before, type));
}

static void	init_node(t_node *node, char *data)
{
	node->cmd_type = get_cmd_type(data);
	node->data = data;
	node->left = NULL;
	node->right = NULL;
}

void	destroy_astree(t_node *root)
{
	if (root == NULL)
	{
		return ;
	}
	destroy_astree(root->left);
	destroy_astree(root->right);
	free(root);
}

t_node	*init_astree_malloc(t_command *command)
{
	t_node	*root;
	t_node	*new_node;
	int		i;

	root = NULL;
	i = 0;
	while (i < command->num_token)
	{
		new_node = (t_node *)malloc(sizeof(t_node));
		init_node(new_node, command->tokens[i]);
		root = insert_astree(root, new_node);
		++i;
	}
	return (root);
}
