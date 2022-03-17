#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/types.h>
#include <dirent.h>

void foo(int sig)
{
	rl_replace_line("", 0);
	printf("\n");
	rl_on_new_line();
	rl_redisplay();
}

int main(void)
{
	char buffer[256];
	DIR* dir = opendir(getenv("HOME"));
	struct dirent* file;

	file = readdir(dir);
	while (file != NULL)
	{
		printf("%s \n", file->d_name);
		file = readdir(dir);
	}
	getcwd(buffer, 256);
	printf("%s", buffer);
	chdir("../");
	getcwd(buffer, 256);
	printf("%s", buffer);
	
	/*char* str;
	signal(SIGINT, foo);
	while (1)
	{
		str = readline("prompt :");
		printf("%s\n", str);
	}*/
}