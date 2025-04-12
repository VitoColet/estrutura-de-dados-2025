#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Implemente um programa em linguagem C que aloque dinamicamente espa�o para armazenar
7 vari�veis do tipo inteiro. Posteriormente, alimente os elementos com valores rand�micos entre
10 e 30. Realoque o vetor para 5 elementos e apresente ao usu�rio, bem como seus respectivos
endere�os de mem�ria.
*/

void preenche_vetor(int *vetor, int tam)
{
	int i;
	for (i=0; i<tam; i++)
	{
		vetor[i] = rand()%21+10;
	}
}

int main(void)
{
	srand(time(NULL));	
	int *vetor_int = malloc(7*sizeof(int));
	int i;
	
	if (!vetor_int)
	{
		printf("Erro ao alocar mem�ria.\n");
	}
	else 
	{
		preenche_vetor(vetor_int, 7);
		realloc(vetor_int, 5*sizeof(int));
		
	}
	
	int tam = 5;
	
	for (i=0; i<tam; i++)
	{
		printf("End: %p | Valor: %d\n", &*(vetor_int+i), *(vetor_int+i));
	}
	
	free(vetor_int);
}
