#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa
{
	char * nome;
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
		printf("%s | %d -> ", head->Pessoa.nome, head->Pessoa.idade);
		head = head->next;
	}
	printf("NULL\n");
	
}

int contar(node * head)
{
	
	int i=0;
		
	while (head!=NULL)
	{
		
		i++;
		head = head->next;
		
	}
	
	return i;
	
}

void limpa_buffer()
{
	int c;
	while ( (c = getchar()) != '\n');
}

void limpar(node *head)
{
	
	while (head != NULL)
	{
		node * temp = head->next;
		free(head->Pessoa.nome);
		free(head);
		head = temp;
	}
	
}

int main(void)
{
	
	int opcao=0;
	node * head = NULL;
	
	do{
		printf("1 - Cadastrar pessoa.\n");
		printf("2 - Listar pessoas.\n");
		printf("3 - Apagar pessoa.\n");
		printf("4 - Sair.\n");
		printf("Sua opcao:");
		scanf("%d", &opcao);
		limpa_buffer();
		
		switch(opcao)
		{
			
			case 1:
				{
				pessoa pessoaTemp;
				char buffer[256];

				system("cls");
				printf("Nome:");
				fgets(buffer, 256, stdin);
				
				for (int i=0; buffer[i] != '\0'; i++)
					if (buffer[i] == '\n')
						buffer[i] = '\0';
				
				pessoaTemp.nome = malloc(strlen(buffer) + 1);
				
				if (!pessoaTemp.nome)
				{
					exit(EXIT_FAILURE);
				}
				
				strcpy(pessoaTemp.nome, buffer);
				printf("Idade:");
				scanf("%d", &pessoaTemp.idade);
				push(&head, pessoaTemp);
				system("cls");
				break;
				}
			case 2:
				system("cls");
				print(head);
				system("pause");
				system("cls");
				break;
			case 3:
				pop(&head);
				system("cls");
				break;
		}
			
	}while(opcao != 4);
	
	
	limpar(head);
}
