#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int num);

int main(int numArgs, char* args[])
{
	int numInputs;
	int lowInput;
	int highInput;
	int diff;
	int i;
	int j;
	int k;
	int* primes;

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

		/*if(diff < 0 || diff > 100000)
		{
			fprintf(stderr,"The the difference of the the second number minus the first number needs to be between 1 and 100000\n");
			exit(EXIT_FAILURE);
		}*/

		primes = (int*)calloc(sizeof(int), diff);

		for(i=lowInput; i <= highInput; i++)
		{
			if(i == 1)
				continue;

			if(isPrime(i))
				primes[j++] = i;
		}

		for(i=0; i < j; i++)
			printf("%d, ", primes[i]);

		free(primes);
	}

	return 0;
}

int isPrime(int num)
{
  int i;
  int max = ceil(sqrt(num));

  for(i=2; i <= max; i++)
  {
    if(num == 2)
	    continue;
    if(!(num%i))
      return 0;
  }

  return 1;
}
