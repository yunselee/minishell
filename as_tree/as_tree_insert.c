/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_tree_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghyk <seunghyk@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:29:17 by seunghyk          #+#    #+#             */
/*   Updated: 2022/04/05 18:01:59 by seunghyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "as_tree.h"

static t_node	*insert_heredoc(t_node *root, t_node *new_node)
{
	if (new_node->cmd_type == CMD_TYPE_ARG && root->right == NULL)
	{
		root->right = new_node;
	}
	else
	{
		root->left = insert_astree(root->left, new_node);
	}
	return (root);
}

static t_node	*insert_redirection(t_node *root, t_node *new_node)
{
	if (new_node->cmd_type == CMD_TYPE_LD_SHIFT)
	{
		new_node->left = root;
		return (new_node);
	}
	if (new_node->cmd_type == CMD_TYPE_PIPE)
	{
		new_node->left = root;
		return (new_node);
	}
	if (new_node->cmd_type == CMD_TYPE_ARG && root->right == NULL)
	{
		root->right = new_node;
	}
	else
	{
		root->left = insert_astree(root->left, new_node);
	}
	return (root);
}

static t_node	*insert_pipe(t_node *root, t_node *new_node)
{
	if (new_node->cmd_type == CMD_TYPE_LD_SHIFT)
	{
		new_node->left = root;
		return (new_node);
	}
	if (new_node->cmd_type == CMD_TYPE_PIPE)
	{
		new_node->left = root;
		return (new_node);
	}
	if (new_node->cmd_type == CMD_TYPE_COMMAND && root->right == NULL)
	{
		root->right = new_node;
	}
	else
	{
		root->right = insert_astree(root->right, new_node);
	}
	return (root);
}

static t_node	*insert_command(t_node *root, t_node *new_node)
{
	if (new_node->cmd_type == CMD_TYPE_ARG)
	{
		root->right = insert_astree(root->right, new_node);
		return (root);
	}
	new_node->left = root;
	return (new_node);
}

t_node	*insert_astree(t_node *root_or_null, t_node *new_node)
{
	if (root_or_null == NULL)
		return (new_node);
	if (root_or_null->cmd_type == CMD_TYPE_L_SHIFT
		|| root_or_null->cmd_type == CMD_TYPE_R_SHIFT
		|| root_or_null->cmd_type == CMD_TYPE_RD_SHIFT)
		return (insert_redirection(root_or_null, new_node));
	if (root_or_null->cmd_type == CMD_TYPE_LD_SHIFT)
		return (insert_heredoc(root_or_null, new_node));
	if (root_or_null->cmd_type == CMD_TYPE_COMMAND
		|| root_or_null->cmd_type == CMD_TYPE_ARG)
		return (insert_command(root_or_null, new_node));
	if (root_or_null->cmd_type == CMD_TYPE_PIPE)
		return (insert_pipe(root_or_null, new_node));
	return (root_or_null);
}
