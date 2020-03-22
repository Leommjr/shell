/* linux alternative shell
 * Written by Leonardo Marinho de Melo Junior <Leommjr>
 * E-mail <miqux@hotmail.com> or <leommjr09@gmail.com>
 *
 * This is bin/bash :)
 * Ref: https://brennan.io/2015/01/16/write-a-shell-in-c/
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
//#include <stdio_ext.h>

#define BUFFER 1024 //please no overflow
#define handle_error(msg) \
	do { perror(msg); exit(EXIT_FAILURE); } while (0)

void loop(void);
char* readl(void);
char** split(char* buffer);
int execute(char** args);
int main(int argc, char* argv[])
{
	loop();
	return 0;
}

void loop(void)
{
	char* line;
	char** args;
	int status;
	do {
	    printf(">> ");
	    line = readl();
            args = split(line);
            status = execute(args);
	} 
	while (status);
	free(args);
	free(line);
}
char* readl(void)
{
	
        int position = 0;
        char* buffer = malloc(BUFFER*sizeof(char));
	if(!buffer)
		handle_error("malloc");
        int c;
	while (1)
	{
		c = getchar();
		if (c == EOF || c == '\n')
		{
			buffer[position] = '\0';
			return buffer;
		}else
		{
			buffer[position] = c;
		        position++;
		}
		if (position >= BUFFER)
		{
		puts("Please, no hack me\n");
		exit(0);
		}
				                                                              }
}
char** split(char* buffer)
{
	int pos = 0, bufs = 64;
	char** args = malloc(sizeof(char*)*bufs);//no need more then 2 args
	char* tok;
	if(!args)
		handle_error("malloc");

	const char s[2] = " ";
	tok = strtok(buffer,s);
	if(tok == NULL)
	{
		handle_error("strtok");
	}
	while(tok != NULL)
	{
		args[pos] = tok;
		pos++;
		if(pos >= bufs)
		{
			puts("No hack me pls\n");
			exit(0);
		}
		tok = strtok(NULL,s);
	}
	return args;
}
int execute(char **args)
{
	  pid_t pid, wpid;
	  int status;
          pid = fork();
	  if (pid <= 0){
		  if(execvp(args[0], args) == -1) {
		      handle_error("execvp");
		   }
	  }else {
		  do {
			  wpid = waitpid(pid, &status, WUNTRACED);
		     }while (!WIFEXITED(status) && !WIFSIGNALED(status));
		return 1;
		 }
}
