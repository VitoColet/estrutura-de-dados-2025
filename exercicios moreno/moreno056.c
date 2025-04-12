#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TOTAL_PESSOAS 5

int main(void)
{
	
	int i;
	char nome_temp[20];
	char **vetor_char = malloc(5*sizeof(char*));
	
	for (i=0; i<TOTAL_PESSOAS; i++)
	{
		printf("%d° Nome:", i+1);
		fgets(nome_temp, 20, stdin);
		printf("\n%d\n", strlen(nome_temp));
		
		vetor_char[i] = malloc(strlen(nome_temp)*sizeof(char));
		strcpy(vetor_char[i], nome_temp);
		printf("%s", vetor_char[i]);
	}
	
}
