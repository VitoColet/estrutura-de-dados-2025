#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa
{
	char nome[30];
	int idade;
}pessoa;

typedef struct node
{
	struct node * next;
	pessoa Pessoa;
}node;

int push(node ** head, pessoa Pessoa)
{
	
	node * temp = (node*) malloc(sizeof(node));
	
	if (!temp)
		return -1;
	
	temp->next = (*head);
	temp->Pessoa = Pessoa;
	
	(*head) = temp;
	return 0;
	
}

void pop(node ** head)
{
	
	node * temp = (*head);
	(*head) = (*head)->next;
	free(temp);
	
}

void print(node * head)
{
	
	while(head != NULL)
	{
		printf("%s | %d ->", head->Pessoa.nome, head->Pessoa.idade);
		head = head->next;
	}
	printf("NULL\n");
	
}

int main(void)
{
	
	pessoa pessoa1 = {"Vitor", 18};
	pessoa pessoa2 = {"Mayara", 20};
	
	node * head=NULL;
	push(&head, pessoa1);
	push(&head, pessoa2);
	
	print(head);
	
}
