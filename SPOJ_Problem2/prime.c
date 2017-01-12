#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

void isPrime(int num);

int* primes;
int j;

int main(int numArgs, char* args[])
{
	int numInputs;
	int lowInput;
	int highInput;
	int diff;
	int i;
	int k;

	primes = (int*)calloc(sizeof(int), 10000);
	if(primes == NULL)
	{
		fprintf(stderr, "not enough memory");
		exit(EXIT_FAILURE);
	}

	if(!scanf("%d", &numInputs) || numInputs < 1 || numInputs > 10)
	{
		fprintf(stderr,"The number of tests needs to be between 1 and 10\n");
		exit(EXIT_FAILURE);
	}

	for(k=0; k < numInputs; k++)
	{
		j = 0;

		if(!scanf("%d", &lowInput) || lowInput < 1 || lowInput > 1000000000)
		{
			fprintf(stderr,"The first number needs to be between 1 and 1000000000\n");
			exit(EXIT_FAILURE);
		}

		if(!scanf("%d", &highInput) || highInput < 1 || highInput > 1000000000)
		{
			fprintf(stderr,"The second number needs to be between 1 and 1000000000\n");
			exit(EXIT_FAILURE);
		}

		diff = highInput - lowInput;

		if(diff < 0 || diff > 100000)
		{
			fprintf(stderr,"The the difference of the the second number minus the first number needs to be between 1 and 100000\n");
			exit(EXIT_FAILURE);
		}


		if(!(lowInput&1))
			lowInput++;

		for(i=lowInput; i <= highInput; i += 2)
		{
			isPrime(i);
		}

		for(i=0; i < j; i++)
			printf("%d\n", primes[i]);
		printf("\n");
	}

	free(primes);
	return 0;
}

void isPrime(int num)
{
	int i;
	int max = ceil(sqrt(num));

	for(i=3; i <= max; i++)
	{
		if(!(num%i))
			return;
	}

	primes[j++] = num;
	return;
}
