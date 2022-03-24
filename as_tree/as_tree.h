#ifdef AS_TREE_H
# define AS_TREE_H

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
	char		*data;
	t_node		*left;
	t_node		*right;
	t_cmd_type	cmd_type;
}				t_node;

t_node		*insert_tree(t_node *root_or_null, char *data);
t_cmd_type	get_cmd_type(char* data);

#endif /* AS_TREE_H */