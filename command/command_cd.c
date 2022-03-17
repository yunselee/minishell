#include <unistd.h>

void change_directory(const char* path)
{
	chdir(path);
}