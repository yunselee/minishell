#include <unistd.h>

void change_directory(const char* path)
{
	if (chdir(path) != 0)
	{
		
	}
}