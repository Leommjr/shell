/* date command for linux x86
 * Written by Leonardo Marinho de Melo Junior <Leommjr>
 * E-mail <miqux@hotmail.com> or <leommjr09@gmail.com>
 *
 * This code should print the date...
 *
 */
#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[])
{
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	printf("%02d/%02d/%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year+1900);
	return 0;
}
