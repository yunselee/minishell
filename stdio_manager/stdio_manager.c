
#include "../allow_function/allow_function.h"
#include <unistd.h>

static int *get_back_up_fd(void)
{
	static int back_up_fd[2];

	return (back_up_fd);
}

void	stdio_back_up(void)
{
	int *back_up_fd;

	back_up_fd = get_back_up_fd();
	back_up_fd[0] = _dup(STDIN_FILENO);
	back_up_fd[1] = _dup(STDOUT_FILENO);
}

void	stdio_recover(void)
{
	const int *back_up_fd = get_back_up_fd();

	_dup2(back_up_fd[0], STDIN_FILENO);
	_dup2(back_up_fd[1], STDOUT_FILENO);
}

void	stdio_close_back_up(void)
{
	const int *back_up_fd = get_back_up_fd();

	_close(back_up_fd[0]);
	_close(back_up_fd[1]);
}
