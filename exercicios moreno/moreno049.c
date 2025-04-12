#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
49) Implemente um programa em linguagem C que aloque dinamicamente espaço para armazenar
10 variáveis do tipo inteiro. Posteriormente, alimente os elementos com valores randômicos
entre 20 e 50. Finalmente, redimensione o vetor para 15 elementos e apresente-os ao usuário
(poderão ser apresentados lixos de memória nos últimos 5 elementos).
*/

void preenche_vetor(int *vetor, int tam)
{
	
	int i;
	
	for (i=0; i<tam; i++)
	{
		*(vetor+i) = rand()%31+20;
	}
	
}

void imprimir_vetor(int *vetor, int tam)
{
	int i;
	for (i=0; i<tam; i++)
	{
		printf("%d", *(vetor+i));
		if (i < tam-1) 
		{
			printf(", ");
		}
	}
}

int main(void)
{
	srand(time(NULL));
	
	int *vetor_int = malloc(10*sizeof(int));
	
	if (!vetor_int)
	{
		printf("Não foi possível alocar a memória necessária.\n");
	}
	else
	{
	preenche_vetor(vetor_int, 10);
	realloc(vetor_int, 15*sizeof(int));
	imprimir_vetor(vetor_int, 15);	
	}
	
	
	free(vetor_int);
}
