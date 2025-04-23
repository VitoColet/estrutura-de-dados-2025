#include "lists.h"

int main(void)
{
	
	node *lista = cria_lista(10);
	imprime_lista(lista);
	delete_tail(lista);
	imprime_lista(lista);
	
}
