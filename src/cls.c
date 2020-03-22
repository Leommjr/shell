/* cls, clear function for linux x86
 * Written by Leonardo Marinho de Melo Junior <Leommjr>
 * E-mail <miqux@hotmail.com> or <leommjr09@gmail.com>
 *
 * This code should clear the screen...
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

#define handle_error(msg) \
	do { perror(msg); exit(EXIT_FAILURE); } while (0)

int getlines(struct winsize w);
int main(int argc, char* argv[])
{
	struct winsize width;
	int lines = getlines(width);
	for(int i =0; i<lines; i++)
	{
		putc(10,stdout);
	}
	return 0;
}
int getlines(struct winsize w)
{
        if(ioctl(STDOUT_FILENO, TIOCGWINSZ, &w)<0)
	{
		handle_error("ioctl");
	}
	return w.ws_row;
}
