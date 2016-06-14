#include "stdio.h"
#include "signal.h"
#include "stdlib.h"

int usr1_counter, usr2_counter;

void usr1_handler(int sno)
{
	usr1_counter++;
}

void usr2_handler(int sno)
{
	usr2_counter++;
}

void term_handler(sno)
{
	printf("%d %d\n", usr1_counter, usr2_counter);
	exit(0);
}

int main(int argc, char const *argv[])
{
	signal(SIGTERM, term_handler);
	signal(SIGUSR1, usr1_handler);
	signal(SIGUSR2, usr2_handler);
	while (1) {}
	return 0;
}