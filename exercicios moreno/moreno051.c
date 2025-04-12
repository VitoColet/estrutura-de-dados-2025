#include <stdio.h>
#include <stdlib.h>

/*
48) Implemente um programa em linguagem C que solicite ao usu�rio a quantidade de elementos
do tipo float que deseja criar dinamicamente. Em seguida, efetue a aloca��o atrav�s da fun��o
MALLOC e apresente a quantidade de bytes alocados caso o processo tenha sido realizado com
�xito.
*/

int main(void)
{
	
	int qntd_elementos;
	float *vetor_float;
	
	printf("Quantidade de elementos no vetor:");
	scanf("%d", &qntd_elementos);
	
	vetor_float = malloc(qntd_elementos*(sizeof(float)));
	
	if (!vetor_float)
	{
		printf("N�o foi poss�vel alocar a mem�ria solicitada");
	}
	else 
	{
		
		printf("Mem�ria Alocada: %d bytes", sizeof(float) * qntd_elementos);
		
	}
	
	free(vetor_float);
}
