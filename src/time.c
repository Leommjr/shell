/* time command for linux x86
 * Written bv Leonardo Marinho de Melo Junior <Leommjr>
 * E-mail <miqux@hotmail.com> or <leommjr09@gmail.com>
 *
 * This code should print the localtime...
 *
 */
#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[])
{
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	printf("%02d/%02d/%02d\n",tm.tm_hour, tm.tm_min, tm.tm_sec);
	return 0;
}
