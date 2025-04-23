#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int value;
	struct Node *next;
} node;

node *cria_node(int valor_node)
{
	node *novo_node = (node*)malloc(sizeof(node));
	novo_node->next = NULL;
	novo_node->value = valor_node;	

	return novo_node;
}

node *cria_lista(int tamanho)
{
	int i;
	node *head = NULL;
	
	for (i=0; i<tamanho; i++)
	{
		node *temp = cria_node(i);
		temp->next = head;
		head = temp;
	}
	
	return head;
}

void delete_tail(node *head)
{
	
	while (head->next->next != NULL)
	{
		head = head->next;
	}
	
	node *temp = head->next;
	free(temp);
	head->next = NULL;
	
}

void imprime_lista(node *head)
{
	
	while (head != NULL)
	{
		printf("%d - ", head->value);
		head = head->next;
	}
	
	printf("NULL\n");
	
}

void atribuir_valores_na_ll(node *head)
{
	
	int i=0;
	
	while (head != NULL)
	{
		i++;
	
		printf("Valor %d:", i);
		scanf("%d", &head->value);
		head = head->next;
	}
	
}

int retorna_qntd_elementos(node *head, int valor_procurado)
{
	
	int qntd_elementos;
	
	while (head != NULL)
	{
		
		if (valor_procurado == head->value)
			qntd_elementos++;
		
		head = head->next;
	}
	
	return qntd_elementos;
	
}

char *transforma_ll_em_str(node *head)
{
	
	while (head != NULL)
	{
		
		head = head->next;
		
	}
	
}
