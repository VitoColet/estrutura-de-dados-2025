#include <stdlib.h>
#include <stdio.h>

#define NAO_REPETIDO 0
#define REPETIDO 1

typedef struct apelido_struct{
  int val;
  struct apelido_struct *prox;
}no;
//---------------------------------------
void inserir_inicio(no **lista, int num){
  no *novo=malloc(sizeof(no));
   if (novo){
    novo->val=num;
    novo->prox=*lista;
    *lista=novo;
  }  
  else
    printf("erro ao alocar memoria \n");   
}
//---------------------------------------
void inserir_fim(no **lista, int num){
  no *aux, *novo=malloc(sizeof(no));
   if (novo){
    novo->val=num;
    novo->prox=NULL;
    if (*lista==NULL)
      *lista=novo;
    else{
      aux=*lista;
      while(aux->prox)
        aux=aux->prox;
      aux->prox=novo;  
    }
  }  
  else
    printf("erro ao alocar memoria \n");   
}
//---------------------------------------
void inserir_ordenado(no **lista, int num){
  no *aux, *novo=malloc(sizeof(no));
  novo->val=num;
  if (*lista==NULL){
    novo->prox=NULL;
    *lista=novo;
  }else if(novo->val<(*lista)->val){
    novo->prox=*lista;
    *lista=novo;
    }else{
    aux=*lista;
    while(aux->prox && novo->val>aux->prox->val)
      aux=aux->prox;
    novo->prox=aux->prox;
    aux->prox=novo;  
  }
}

void inserir_sem_rep(no **head, int value)
{
	
	int repetido=NAO_REPETIDO;
	no *temp = (*head);
	
	while ( temp && repetido == 0)
	{
		
		if (temp->val == value)
		{
			repetido = REPETIDO;
			printf("Valor repetido.\n");
			system("pause");
		}
		
		temp = temp->prox;
	}
	
	
	if (repetido == NAO_REPETIDO)
	{
		no * temp = malloc(sizeof(no));
		temp->val = value;
		temp->prox = (*head);
		
		(*head) = temp;
	}
	
	
}

void remover(no ** head, int value)
{
	
	if ((*head) == NULL)
	{
		printf("Lista vazia\n.");
		system("pause");
		return;
	}
	
	no * temp = (*head);
	no * temp_antecessor = temp;
	int i=0;
	while (temp)
	{
		i++;
		
		if (i > 2)
			temp_antecessor = temp_antecessor->prox;
		
		if (temp->val == value && i==1)
	    {
	      no * aux = temp;
	      temp = temp->prox;
	      free(aux);
	      (*head) = temp;
	      
	      return;
	    }
	    else if (temp->val == value && i > 1)
	    {
	    	temp_antecessor->prox = temp->prox;
	    	free(temp);
	    	return;
		}
	
		temp = temp->prox;
  }
  
}

void imprimir(no *no){
  printf("\nLista: ");
  while (no){
    printf("%d ",no->val);
    no=no->prox;
  }
  printf("\n\n");
}
//-------------------------------------
int main() {
  no *lista=NULL;
  int opcao,val,anterior;
  do{
    printf("\n1 inserir no inicio");
    printf("\n2 inserir no final");
    printf("\n3 inserir ordenado");
    printf("\n4 insirir sem rep");
    printf("\n5 remover");
    printf("\n6 imprimir");
    printf("\n7 fim");
    printf("\nopcao: ");
    fflush(stdin);
    scanf("%d",&opcao);
    switch (opcao) {
      case 1:
        printf("\nval a inserir: ");
        fflush(stdin);
        scanf("%d",&val);
        inserir_inicio(&lista,val);
        break;
      case 2:
        printf("\nval a inserir: ");
        fflush(stdin);
        scanf("%d",&val);
        inserir_fim(&lista,val);
        break;
      case 3:
        printf("\nval a inserir: ");
        fflush(stdin);
        scanf("%d",&val);
        inserir_ordenado(&lista,val);
        break;
      case 4:
      		printf("val a inserir:");
      		fflush(stdin);
      		scanf("%d", &val);
      		inserir_sem_rep(&lista, val);
        break;
      case 5:
      	printf("val a remover:");
      	fflush(stdin);
      	scanf("%d", &val);
      	remover(&lista, val);
      	break;
      case 6:
        imprimir(lista);     
        system("pause");
        break;
     } 
     system("cls");
  }
  while (opcao!=7); 
  system("pause");
  return 0;
}
