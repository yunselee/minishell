#include "libft/libft.h"
#include "exit_code.h"
#include <fcntl.h>
#include <unistd.h>
#include "allow_function/allow_function.h"
#include "as_tree/as_tree.h"

#define CHILD 0
# define HEREDOC_DIR "./.heredoc"

void close_pointer(int fd[]);
void wait_pid_and_set_exit_code(pid_t child);
void connect_file_to_std (const char *pathname, int path_open_flags, int path_open_mode, int std_fd);
void	execute_basic_cmd(t_node *astree);

//fork와 fd연관해서 다시 읽기;
static void	set_pipe_recursive(t_node *astree)
{
	int		pipe_fd[2];
	pid_t	child;
	int		exit_code;

	pipe(pipe_fd);
	child = _fork();
	if (child == CHILD)
	{
		_dup2(pipe_fd[1], STDOUT_FILENO);
		close_pointer(pipe_fd);
		execute_recursive(astree->left);
		exit(EXIT_SUCCESS);
	}
	wait_pid_and_set_exit_code(child);
	child = _fork();
	if (child  == CHILD)
	{
		_dup2(pipe_fd[0], STDIN_FILENO);
		close_pointer(pipe_fd);
		execute_recursive(astree->right);
		exit(EXIT_SUCCESS);
	}
	wait_pid_and_set_exit_code(child);
	close_pointer(pipe_fd);
}

static void	execute_heredoc(t_node *astree)
{
	const char	*eof = astree->right->data;
	const pid_t	child = fork();
	int fd;

	if (child == CHILD)
	{
		stdio_recover();
		fd = _open(HEREDOC_DIR, O_WRONLY | O_CREAT, S_IRWXU);
		rl_until_sign(eof, fd);
		exit(EXIT_SUCCESS);
	}
	wait_pid_and_set_exit_code(child);
	connect_file_to_std(HEREDOC_DIR, O_RDONLY, S_IRWXU, STDIN_FILENO);
}

static void	set_rdr_recursive(t_node *astree)
{
	const char *path = astree->right->data;
	int			file_fd;

	if (astree->cmd_type == CMD_TYPE_R_SHIFT)
	{
		connect_file_to_std(path, O_WRONLY | O_CREAT, S_IRWXU, STDOUT_FILENO);
	}
	else if (astree->cmd_type == CMD_TYPE_RD_SHIFT)
	{
		connect_file_to_std(path, O_WRONLY | O_CREAT | O_APPEND, S_IRWXU, STDOUT_FILENO);
	}
	else if (astree->cmd_type == CMD_TYPE_L_SHIFT)
	{
		file_fd = _open(path, O_RDONLY, S_IRWXU);
		if(file_fd == -1)
			return;
		_dup2(file_fd, STDIN_FILENO);
		_close(file_fd);
	}
	else if (astree->cmd_type == CMD_TYPE_LD_SHIFT)
	{
		execute_heredoc(astree);
	}
	execute_recursive(astree->left);
}

void	execute_recursive(t_node *astree)
{
	if (astree->cmd_type == CMD_TYPE_PIPE)
	{
		set_pipe_recursive(astree);
		return ;
	}
	else if (astree->cmd_type == CMD_TYPE_L_SHIFT \
		|| astree->cmd_type == CMD_TYPE_LD_SHIFT \
		|| astree->cmd_type == CMD_TYPE_R_SHIFT \
		|| astree->cmd_type == CMD_TYPE_LD_SHIFT)
	{
		set_rdr_recursive(astree);
		return ;
	}
	execute_basic_cmd(astree);
}

void	excute_command(char *line)
{
	const t_node	*astree = set_astree(get_token(line));

	stdio_back_up();
	if (!check_syntax(astree))
		printf("Syntax Error\n");
	else
	{
		execute_recursive(astree);
	}
	delete_astree(astree);
	stdio_recover();
	stdio_close_back_up_fd();
}
