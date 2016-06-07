#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"

int fd; 

int get_ppid(int pid)
{
	int ppid;
	FILE * f;
	char path[100];
	sprintf(path, "/proc/%d/stat", pid);
	f = fopen(path, "r");
	
	fscanf(f, "%*d %*s %*c %d", &ppid);

	return ppid;
}

int main(int argc, char const *argv[])
{
	int id = atoi(argv[1]);
	printf("%d\n", id);
	while (id != 1)
	{
		id = get_ppid(id);
		printf("%d\n", id);
	}
}