#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int numArgs, char* args[])
{
	int input;

	while(1)
	{
		if(!scanf("%d", &input))
		{
			fprintf(stderr, "there was invalid input\n");
			exit(EXIT_FAILURE);
		}

		if(input == 42)
			break;

		printf("%d\n", input);
	}

	return 0;
}
