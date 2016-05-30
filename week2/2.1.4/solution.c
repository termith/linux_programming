#include <getopt.h>
#include <stdlib.h>
#include <stdio.h>

char* result = "+";
int rez;
int option_index;

int main(int argc, char *argv[])
{	
	opterr = 0;
	const char* short_options = "qiv";

	const struct option long_options[] = {
		{"query",optional_argument,NULL,'q'},
		{"longinformationrequest",optional_argument,NULL,'i'},
		{"version",optional_argument,NULL,'v'},
		{NULL,0,NULL,0}
	};

	while ((rez=getopt_long_only(argc,argv,short_options,
		long_options,&option_index))!=-1){

		switch(rez){
			case 'q': {
				if (optarg == NULL)
					result = "-";
				break;
			};
			case 'i':
			case 'v':{
				continue;
			};
	
			default: {
				result = "-";
				break;
			};
		};
	};
	printf("%s\n", result);
	return 0;
}
