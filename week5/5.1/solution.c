#include "stdio.h"
#include "string.h"

int main(int argc, char const *argv[])
{	
	char command[100];
	strcpy(command, argv[1]);
	strcat(command, " ");
	strcat(command, argv[2]);

	int counter = 0;
	FILE *out = popen(command, "r");

	while (1)
	{
		int c = fgetc(out);
		if (c == EOF)
		{	
			printf("%d\n", counter);
			pclose(out);
			break;
		}
		else if(c == 48)
		{
			counter++;
		}
	}
	return 0;
}