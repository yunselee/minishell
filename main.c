#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>
#include <dirent.h>
#include "libft/libft.h"
#include "command_processor.h"
#include "command_initializer/command_initializer.h"
#include "env_variable/env_variable.h"
#include "as_tree/as_tree.h"

static void print_command(t_command *command);
static void register_all_env(const char **envp);
static void print_envs(char **envs);
void print_tree(t_node* root);
void print_tree_node(t_node* node, bool is_right, char *indent);

int main(int argc, const char **argv, const char **envp)
{
	t_command	command;
	char		*text;
	t_node* 	root;

	register_all_env(envp);
	while (1)
	{
		text = readline("Prompt :");
		{
			if (try_init_command(text, &command))
			{
				if (ft_strncmp(command.tokens[0], "exit", 4) == 0)
				{
					free(text);
					return (0);
				}
				root = init_astree_malloc(&command);
				print_tree(root);
			}
		}
		destroy_astree(root);
		root = NULL;
		free(text);
	}
	return (0);
}

char* ft_strcat(char *dest, char *src)
{
	char* p_dest;
	char* p_src;

	p_dest = dest;
	while (*p_dest != '\0')
	{
		p_dest++;
	}
	p_src = src;
	while (*p_src != '\0')
	{
		*p_dest++ = *p_src++;
	}
	*p_dest = '\0';
	return dest;
}

void print_tree(t_node* root)
{
	char indent[1024] = "";
	if (root->right != NULL)
	{
		print_tree_node(root->right, true, "");
	}
	printf("[%s]\n", root->data);
	if (root->left != NULL)
	{
		print_tree_node(root->left, false, "");
	}
}

void print_tree_node(t_node* node, bool is_right, char *indent)
{
	char r_indent[512];
	char l_indent[512];
	ft_strlcpy(r_indent, indent , 512);
	ft_strlcpy(l_indent, indent , 512);
	if (node->right != NULL)
	{
		print_tree_node(node->right, true, ft_strcat(r_indent, is_right ? "        " : " |      "));
	}
	printf("%s", indent);
	if (is_right)
	{
		printf(" /");
	}
	else
	{
		printf(" \\");
	}
	printf("----- ");
	printf("[%s]\n", node->data);
	if (node->left != NULL)
	{
		print_tree_node(node->left, false, ft_strcat(l_indent, is_right ? "        " : " |      "));
	}
}

static void print_envs(char **envs)
{
	char **p_envs;

	p_envs = envs;
	while (*p_envs != NULL)
	{
		printf("%s\n", *p_envs);
		++p_envs;
	}
}

static void print_command(t_command *command)
{
	int i;


	i = 0;
	while (i < command->num_token)
	{
		printf("%s\n", command->tokens[i]);
		++i;
	}
}

static void register_all_env(const char **envp)
{
	const char	**p_envp;
	char		**tokens;

	p_envp = envp;
	while (*p_envp != NULL)
	{
		tokens = ft_split(*p_envp, '=');
		register_env_variable(tokens[0], tokens[1]);
		free(tokens[0]);
		free(tokens[1]);
		++p_envp;
	}
}