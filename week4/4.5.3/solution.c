#include "stdio.h"
#include "dirent.h"
#include "string.h"
#include "unistd.h"
#include "stdlib.h"


int main(int argc, char const *argv[])
{
	int counter = 0;

	DIR *proc = opendir("/proc");
	struct dirent *entry;
	
	// For every directory in proc
	while (entry = readdir(proc))
	{
		if (entry->d_type == DT_DIR)
		{
			char path[100];
			char name[100];
			long int pid = strtol(entry->d_name, NULL, 10);
			if (pid != 0)
			{
				sprintf(path, "/proc/%d/comm", (int)pid);
				FILE *f = fopen(path, "r");
				fscanf(f, "%s", &name);
				int is_equal = strcmp("genenv", name);
				if (is_equal == 0)
					counter++;
			}
		}
	}
	printf("%d\n", counter);
	return 0;
}
