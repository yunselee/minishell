#include <unistd.h>
#include "../allow_function/allow_function.h"
#include "../exit_code/exit_code.h"

void close_pointer(int fd[])
{
	_close(fd[1]);
	_close(fd[0]);
}

void wait_pid_and_set_exit_code(pid_t child)
{
	int exit_code;

	_waitpid(child, &exit_code, 0);
	exit_code_set(exit_code);
}

void connect_file_to_std (const char *pathname, \
	int path_open_flags, int path_open_mode, int std_fd)
{
	const int file_fd = _open(pathname, path_open_flags, path_open_mode);

	if(file_fd == -1)
		return;
	_dup2(file_fd, std_fd);
	_close(file_fd);
}
