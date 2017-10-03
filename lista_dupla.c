/*************************
  UFFS CHAPECÓ
  github: barbs-pm
  Barbara Pegoraro Markus

  LISTA DUPLA ENCADEADA
**************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#define TAM 100

typedef struct produto{
	int codigo;
	char nome[TAM];
	float preco;
}tp_produto;

typedef struct nodo{
	tp_produto produto;
	struct nodo *next;
	struct nodo *prev;
}tp_nodo;


typedef struct lista{
	int nItens;
	tp_nodo *first;
	tp_nodo *last;
}tp_lista;

//função que push um nodo e retorna a lista atualizada
void push(tp_lista *head){
	tp_nodo* novo = (tp_nodo*) malloc(sizeof(tp_nodo));
	
	novo->next = NULL;
	novo->prev = head->last;

	if(head->nItens == 0) head->first = novo;
	else (novo->prev)->next = novo;

	head->last = novo;	

	system("clear"); 
	printf("\t___________~<>~___________\n");
	printf("\tCódigo do produto: ");
	scanf("%d", &novo->produto.codigo);
	printf("\tNome: ");
	getchar();
	fgets(novo->produto.nome, TAM, stdin);
	printf("\tPreço: ");
	scanf("%f", &novo->produto.preco);

	(head->nItens)++;

}

void pop(tp_lista *head){
	int codiguinho, volta, cont=0;
	tp_nodo *aux, *endereco;	//p = variável auxiliar, ant = guardará a ultima posição percorrida,
								//endereco = receberá posição atual do p para poder apontar um a frente depois
	
	if(head->nItens == 0) { //se a função vazia for verdadeira retorna a lista
		system("clear");
		printf("\t___________~<>~__________\n");
		printf("\tLista vazia.\n");
		printf("\tAperte 1 para voltar: ");
		scanf("%d", &volta);
	}

		
	else{
		system("clear");
		printf("\t___________________~<>~__________________\n");
		printf("\tCódigo do produto que deseja retirar: ");
		scanf("%i",&codiguinho);

		for(aux = head->first; aux != NULL; aux = aux->next){  // percorre todos os elementos da lista
			if((aux->produto).codigo == codiguinho){	//compara se o código do produto é igual ao digitado pelo usuario
				cont = 1;
				if(aux == head->first){
					endereco = head->first;
					head->first = (head->first)->next;
					endereco->prev = NULL;	
					(head->nItens)--;			
				}
				
				else if(aux == head->last){ //caso esteja no last exclui o produto e faz o reaponteiramento.
					endereco = head->last;
					head->last = (head->last)->prev;
					(head->last)->next = NULL;
					(head->nItens)--;
				}
				else{
					(aux->next)->prev = aux->prev;
					(aux->prev)->next = aux->next;
					(head->nItens)--;				
				}
			}
		}

		if(cont == 0){
			system("clear");
			printf("\t____________~<>~___________\n");
			printf("\tProduto não encontrado\n");	//se o produto não existir, retornará a própria lista
			printf("\tAperte 1 para voltar: ");
			scanf("%d", &volta);
		}
	}
}

void display(tp_lista *head){
	tp_nodo *aux; //p recebe head que aponta pro ultimo da lista
	int volta;
	
	system("clear");

	
	printf("\t___________~<>~__________\n");

	for(aux = head->first; aux != NULL; aux = aux->next){
		printf("\tCódigo do produto: %d\n", (aux->produto).codigo);
		printf("\tNome: %s", (aux->produto).nome);
		printf("\tPreço: %.2f", (aux->produto).preco);
		printf("\n\n");
	}
	printf("\t___________~<>~__________\n");

	if(head->nItens == 0) { //se a função vazia for verdadeira retorna a lista
		system("clear");
		printf("\t___________~<>~__________\n");
		printf("\tLista vazia.\n");
	}
	printf("\tAperte 1 para voltar: ");
	scanf("%d", &volta);
}

void libera(tp_lista *head){
	tp_nodo *aux, *lib;
	
	for(aux = (head->first)->next; aux != NULL; aux = aux->next){
		lib = aux->prev;
		free(lib);
	}
}

int main(void){
	int op;

	tp_nodo *l = NULL; //cria uma lista vazia
	tp_lista *head = malloc(sizeof(head));

	head->last = NULL;
	head->first = NULL;
	head->nItens = 0;
	
	do{
		system("clear");
		printf("\t___________~<>~__________\n");
		printf("\t|0| Sair\n");
		printf("\t|1| Inserir produto\n");
		printf("\t|2| Excluir produto\n");
		printf("\t|3| Exibir lista\n");
		printf("\t___________~<>~__________\n");
		printf("\tEscolha sua opção: ");
		scanf("%d", &op);

		switch(op){
			case 1: push(head); break;
			case 2: pop(head); break;
			case 3: display(head); break;
		}
	
	} while(op != 0);

	free(l);
	free(head);

	return 0;
}