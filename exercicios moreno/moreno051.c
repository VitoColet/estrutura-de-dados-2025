#include <stdio.h>
#include <stdlib.h>

/*
48) Implemente um programa em linguagem C que solicite ao usuário a quantidade de elementos
do tipo float que deseja criar dinamicamente. Em seguida, efetue a alocação através da função
MALLOC e apresente a quantidade de bytes alocados caso o processo tenha sido realizado com
êxito.
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
		printf("Não foi possível alocar a memória solicitada");
	}
	else 
	{
		
		printf("Memória Alocada: %d bytes", sizeof(float) * qntd_elementos);
		
	}
	
	free(vetor_float);
}
