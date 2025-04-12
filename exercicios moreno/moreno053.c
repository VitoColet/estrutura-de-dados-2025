#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

/*
53) Construa um programa em linguagem C que aloque dinamicamente um vetor com 10
elementos inteiros com valores randomizados a seu crit�rio. Posteriormente, efetue uma
realoca��o para 20 elementos e apresente ao usu�rio uma mensagem dizendo se houve ou n�o
mudan�a de endere�o do vetor ap�s o realloc.
*/

void preenche_vetor(int *vetor, int tam)
{
	
	int i;
	for (i=0; i<tam; i++)
	{
		vetor[i] = rand()%50+1;
	}
	
}

int main(void)
{
	
	setlocale(LC_ALL, "portuguese");
	
	int *vetor_int = malloc(10*sizeof(int));
	int *primeiro_endereco = vetor_int;
	
	if (!vetor_int)
	{
		printf("Erro na aloca��o de mem�ria.\n");
	}
	else
	{
		preenche_vetor(vetor_int, 10);
		realloc(vetor_int, 20*(sizeof(int)));
		
	}
	
	if (!vetor_int)
	{
		printf("Erro na aloca��o.\n");
		return 1;
	}
	else
	{
		printf("Endere�o original: %p\n", primeiro_endereco);
		printf("Endere�o atual: %p\n", vetor_int);
		
		if (vetor_int != primeiro_endereco)
		{
			printf("Um bloco de mem�ria diferente foi alocado.\n");
		}
		else {
			printf("O mesmo bloco foi utilizado para a re-aloca��o.\n");
		}
	}
	
	
	free(vetor_int);	
	
}
