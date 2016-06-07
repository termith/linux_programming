#include "stdio.h"
#include "dirent.h"
#include "string.h"

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
			char *name;
			sprintf(path, "/proc/%s/comm");
			FILE *f = fopen(path, "r");
			fscanf(f, "%s", name);
			if (strcmp(entry->d_name, "genenv") == 0)
				counter++;
		}
	}
	printf("%d\n", counter);
	return 0;
}
