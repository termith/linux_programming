#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <dlfcn.h>
#include <unistd.h>

int (*someSecretFunction)(int a);


int main(int argc, char* argv[])
{	
	void *hdl = dlopen(argv[1], RTLD_LAZY);
	someSecretFunction = (int (*)(int))dlsym(hdl, argv[2]);
	printf("%d\n", someSecretFunction(atoi(argv[3])));
	return 0;
}
