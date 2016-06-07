#include "stdio.h"
#include "unistd.h"

int fd; 
int ppid;

int main(int argc, char const *argv[])
{
	// Open file /proc/self/status
	FILE * f = fopen("/proc/self/stat", "r");
	// Parse ppid from string
	fscanf(f, "%*d %*s %*c %d", &ppid);
	// Print ppid
	printf("%d\n", ppid);
	return 0;
}