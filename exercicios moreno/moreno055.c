#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	srand(time(NULL));
	
	int **matriz = malloc(5*sizeof(int*));
	int linha, coluna;
	
	for (linha=0; linha<=4; linha++)
	{
		matriz[linha] = malloc(4*sizeof(int));
	}
	
	for (linha=0; linha<5; linha++)
	{
		for (coluna=0; coluna<4; coluna++)
		{
			matriz[linha][coluna] = rand()%101+100;
		}
	}
	
	for (linha=0; linha<5; linha++)
	{
		
		printf("Linha %d : ", linha+1);
		
		for (coluna=0; coluna<4; coluna++)
		{
			printf("%d", *(*(matriz+linha)+coluna) );
			if (coluna < 3)
			{
				printf(", ");
			}
		}
		
		printf("\n");
	}
	
}

