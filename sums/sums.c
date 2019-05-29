#include <stdio.h>

int main(int argc, char **argv)
{
	for(int ndx=0; ndx<argc; ++ndx) {
		printf("Arg %d of %d = %s\n", ndx, argc, argv[ndx]);
	}

	printf("\n Done!\n");
	return 0;
}
