#include <stdlib.h>

#include "../libft/libft.h"
#include "as_tree.h"

static t_cmd_type	get_cmd_type(char *data)
{
	static t_cmd_type	before = CMD_TYPE_NONE;
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
		type = CMD_TYPE_PIPE;
	else if (before == CMD_TYPE_NONE || before == CMD_TYPE_PIPE)
		type = CMD_TYPE_COMMAND;
	else
		type = CMD_TYPE_ARG;
	if (type == CMD_TYPE_ARG && CMD_TYPE_L_SHIFT <= before)
		before = CMD_TYPE_NONE;
	else
		before = type;
	return (type);
}

static void init_node(t_node *node, char *data)
{
	node->cmd_type = get_cmd_type(data);
	node->data = data;
	node->left = NULL;
	node->right = NULL;
}

void	destroy_astree(t_node* root)
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
		new_node = (t_node*)malloc(sizeof(t_node));
		init_node(new_node, command->tokens[i]);
		root = insert_astree(root, new_node);
		++i;
	}
	return (root);
}
