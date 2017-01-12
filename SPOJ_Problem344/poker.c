#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

typedef struct 
{
	char val;
	char suite;
} card;

int isRF(card* c);
int isSF(card* c);
int is4(card* c);
int isFH(card* c);
int isF(card* c);
int isS(card* c);
int is3(card* c);
int is2P(card* c);
int is2(card* c);

int h4, h3, h2_1, h2_2, str, same;

int main(int numArgs, char* args[])
{
	card* cards;
	int numHands;
	int i;
	char c;
	int cur;

	if(!scanf("%d", &numHands) || numHands < 1 || numHands > 20)
	{
		fprintf(stderr, "the number of hands must be between 1 and 20\n");
		exit(EXIT_FAILURE);
	}

	for(i=0; i < numHands; i++)
	{
		h4 = 0; 
		h3 = 0; 
		h2_1 = 0; 
		h2_2 = 0; 
		str = 0; 
		same = 1;
		cards = (card*)malloc(sizeof(card)*5);
		cur = 0;
		while((c=getc(stdin)))
		{
			if(cur == 5)
				break;

			if(isalpha(c) || isdigit(c))
			{
				cards[cur].val = c;
				c = getc(stdin);
				cards[cur++].suite = c;
			}
		}

		if(isRF(cards) || isSF(cards) || is4(cards) || isFH(cards) || isF(cards) || isS(cards) || is3(cards) || is2P(cards) || is2(cards))
		{
			free(cards);
			continue;
		}

		printf("high card\n");

		free(cards);
	}

	return 0;
}

int isRF(card* c)
{
	int* order = (int*)calloc(sizeof(int), 13);
	int s = c[0].suite;
	int i;

	for(i=0; i < 5; i++)
	{
		if(c[i].suite != s)
			same = 0;

		switch(c[i].val)
		{
			case 'A':
				order[12] = 1;
				break;
			case 'K':
				order[11] = 1;
				break;
			case 'Q':
				order[10] = 1;
				break;
			case 'J':
				order[9] = 1;
				break;
			case 'T':
				order[8] = 1;
				break;
			case '9':
				order[7] = 1;
				break;
			case '8':
				order[6] = 1;
				break;
			case '7':
				order[5] = 1;
				break;
			case '6':
				order[4] = 1;
				break;
			case '5':
				order[3] = 1;
				break;
			case '4':
				order[2] = 1;
				break;
			case '3':
				order[1] = 1;
				break;
			case '2':
				order[0] = 1;
				break;
			default:
				fprintf(stderr, "Something went wrong\n");
				exit(EXIT_FAILURE);
		}
	}

	if(order[12] && order[0] && order[1] && order[2] && order[3])
	{
		str = 1;
	}

	for(i=0; i < 9; i++)
	{
		if(order[i] && order[i+1] && order[i+2] && order[i+3] && order[i+4])
		{	
			str = 1;
		}
	}

	if(same && str && order[12])
	{
		printf("royal flush\n");
		return 1;
	}

	free(order);

	return 0;
}

int isSF(card* c)
{
	if(same && str)
	{
		printf("straight flush\n");
		return 1;
	}

	return 0;
}

int is4(card* c)
{
	int* order = (int*)calloc(sizeof(int), 13);
	int i;

	for(i=0; i < 5; i++)
	{
		switch(c[i].val)
		{
			case 'A':
				order[12]++;
				break;
			case 'K':
				order[11]++;
				break;
			case 'Q':
				order[10]++;
				break;
			case 'J':
				order[9]++;
				break;
			case 'T':
				order[8]++;
				break;
			case '9':
				order[7]++;
				break;
			case '8':
				order[6]++;
				break;
			case '7':
				order[5]++;
				break;
			case '6':
				order[4]++;
				break;
			case '5':
				order[3]++;
				break;
			case '4':
				order[2]++;
				break;
			case '3':
				order[1]++;
				break;
			case '2':
				order[0]++;
				break;
			default:
				fprintf(stderr, "Something went wrong\n");
				exit(EXIT_FAILURE);
		}
	}

	for(i=0; i < 13; i++)
	{
		if(order[i] == 4)
			h4 = 1;
		else if (order[i] == 3)
			h3 = 1;
		else if(order[i] == 2 && !h2_1)
			h2_1 = 1;
		else if(order[i] == 2 && h2_1)
			h2_2 = 1;
	}

	if(h4)
	{
		printf("four of a kind\n");
		return 1;
	}

	free(order);
	return 0;
}

int isFH(card* c)
{
	if(h3 && h2_1)
	{
		printf("full house\n");
		return 1;
	}

	return 0;
}

int isF(card* c)
{
	if(same)
	{
		printf("flush\n");
		return 1;
	}

	return 0;
}

int isS(card* c)
{
	if(str)
	{
		printf("straight\n");
		return 1;
	}

	return 0;
}

int is3(card* c)
{
	if(h3)
	{
		printf("three of a kind\n");
		return 1;
	}

	return 0;
}

int is2P(card* c)
{
	if(h2_1 && h2_2)
	{
		printf("two pairs\n");
		return 1;
	}

	return 0;
}

int is2(card* c)
{
	if(h2_1)
	{
		printf("pair\n");
		return 1;
	}

	return 0;
}
