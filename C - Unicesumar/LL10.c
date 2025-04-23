#include "lists.h"

// Achar a quantidade de determinado valor em uma LL.

int main(void)
{
	node *head;
	
	int tam_LL, i;
	int *vet_valores;
	
	printf("Tamanho da LL:");
	scanf("%d", &tam_LL);
	
	head = cria_lista(tam_LL);
	
	atribuir_valores_na_ll(head);
	
	imprime_lista(head);
	
	printf("Qntd de 5 na LL: %d\n", retorna_qntd_elementos(head, 5));
}
