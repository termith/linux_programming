#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "dirent.h"

int get_ppid(int pid)
{
	int ppid;
	FILE * f;
	char path[100];
	sprintf(path, "/proc/%d/stat", pid);
	f = fopen(path, "r");
	
	fscanf(f, "%*d %*s %*c %d", &ppid);
	close(f);
	return ppid;
}

int main(int argc, char const *argv[])
{
	int target_pid = atoi(argv[1]);
	int counter = 1;

	DIR *proc = opendir("/proc");
	struct dirent *entry;
	
	// For every directory in proc
	while (entry = readdir(proc))
	{
		if (entry->d_type == DT_DIR)
		{
			long int pid = strtol(entry->d_name, NULL, 10);
			if (pid != 0)
			{
				int ppid = get_ppid(pid);
				if (ppid == target_pid )
					counter++;
			}
		}
	}
	printf("%d\n", counter);
	return 0;
}