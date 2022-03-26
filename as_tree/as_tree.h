#ifndef AS_TREE_H
# define AS_TREE_H

#include "../command_initializer/command_initializer.h"

typedef enum	e_cmd_type
{
	CMD_TYPE_COMMAND,
	CMD_TYPE_ARG,
	CMD_TYPE_PIPE,
	CMD_TYPE_L_SHIFT,
	CMD_TYPE_R_SHIFT,
	CMD_TYPE_LD_SHIFT,
	CMD_TYPE_RD_SHIFT,
	CMD_TYPE_NONE
}				t_cmd_type;

typedef struct	s_node
{
	char				*data;
	struct s_node		*left;
	struct s_node		*right;
	t_cmd_type			cmd_type;
}				t_node;

t_node	*insert_astree(t_node *root_or_null, t_node *new_node);
t_node	*init_astree_malloc(t_command *command);
void	destroy_astree(t_node* root);

#endif /* AS_TREE_H */