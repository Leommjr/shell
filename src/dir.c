/* dir, ls command for linux x86
 * Written by Leonardo Marinho de Melo Junior <Leommjr>
 * E-mail <miqux@hotmail.com> or <leommjr09@gmail.com>
 *
 * This code should list all files in directory...
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <linux/limits.h>

#define handle_error(msg) \
	do { perror(msg); exit(EXIT_FAILURE); } while (0)

void listenDir(DIR *dir, struct dirent* entry);
int main(int argc, char* argv[])
{
	char curDir[PATH_MAX];
	DIR* dir;
	struct dirent* entry;

	if(argc != 2)
	{
		if(getcwd(curDir,sizeof(curDir)) == NULL)
			handle_error("getcwd");
		dir = opendir(curDir);
		if(dir == NULL)
			handle_error("opendir");
		listenDir(dir, entry);
	}
	else
	{
		dir = opendir(argv[1]);
		if(dir == NULL)
			handle_error("opendir");
		listenDir(dir, entry);
	}
	return 0;
}
void listenDir(DIR *dir, struct dirent* entry)
{
	while(entry = readdir(dir))
		puts(entry->d_name);
	closedir(dir);
}

