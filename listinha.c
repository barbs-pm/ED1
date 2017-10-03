/*************************
UFFS CHAPECÓ
github: barbs-pm
Barbara Pegoraro Markus

LISTA SIMPLES ENCADEADA
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
	struct nodo *prox;
}tp_nodo;


//função que cria e retorna uma lista vazia
tp_nodo* cria(){
	return NULL;
}

/**********************************************
essa função recebe a lista, cria uma variável
para percorrer ela, e caso encontre um elemento
ela retorna como falsa na outra função que chama
ela, se ela percorrer o for inteiro e não 
encontrar nada, p tera valor NULL e entrará no if
retornando verdadeira para a outra função.
**********************************************/
int vazia(tp_nodo *l){
	tp_nodo *p;

	for(p = l; p != NULL; p = p->prox)
		if(p != NULL) return 0;
		
	if(p == NULL) return 1;
}

//função que push um nodo e retorna a lista atualizada
tp_nodo* push(tp_nodo *l){
	tp_nodo* novo = (tp_nodo*) malloc(sizeof(tp_nodo)); //cria um novo nodo do tamanho necessário
	
	system("clear");                                  //adiciona as informações do novo nó
	printf("\t___________~<>~___________\n");
	printf("\tCódigo do produto: ");
	scanf("%d", &(novo->produto).codigo);
	printf("\tNome: ");
	getchar();
	fgets((novo->produto).nome, TAM, stdin);
	printf("\tPreço: ");
	scanf("%f", &(novo->produto).preco);

	novo->prox = l;	 //novo->prox recebe a lista e aponta para nó anterior
	
	return novo; //retorna novo nó criado

}

tp_nodo* pop(tp_nodo *l){
	int codiguinho, volta;
	tp_nodo *p,*ant, *endereco;	//p = variável auxiliar, ant = guardará a ultima posição percorrida,
								//endereco = receberá posição atual do p para poder apontar um a frente depois
	ant = NULL;

	if(vazia(l)) { //se a função vazia for verdadeira retorna a lista
		system("clear");
		printf("\t___________~<>~__________\n");
		printf("\tLista vazia.\n");
		printf("\tAperte 1 para voltar: ");
		scanf("%d", &volta);
		return l; 
	}

	system("clear");
	printf("\t___________________~<>~__________________\n");
	printf("\tCódigo do produto que deseja retirar: ");
	scanf("%i",&codiguinho);

	/***************************************************
	nessa parte do programa, faço um for para 
	procurar o elemento da lista que possui o
	mesmo código digitado pelo usuário, para isso
	preciso criar uma variavel (codiguinho) para
	comparar as duas. Caso encontre, entra em 
	outro if, que vê se o elemento é o ultimo
	adicionado pelo usuário, se for, o anterior a 
	ele é NULL, então ele fará uma copia do 
	penultimo para o ultimo, ou seja (ultimo = penultimo)
	e o penultimo desaparece. Se ele não esta na ultima
	posição, então ele esta no meio, ou será o 1°, assim,
	faço um reaponteiramento. O anterior que apontava 
	para seu proximo (p, que esta sendo excluido), recebe
	o proximo apontado pelo p.
	****************************************************/

	for(p = l; p != NULL; p = p->prox){  // percorre todos os elementos da lista
		if((p->produto).codigo == codiguinho){	//compara se o código do produto é igual ao digitado pelo usuario
			endereco = p;
			if(ant == NULL){ //caso seja o ultimo adicionado
				p = p->prox;
				return p;
			}
			
			else{ //caso esteja no meio exclui o produto e faz o reaponteiramento.
				ant->prox = endereco->prox;
				return l;
			}
		}
		
		else ant = p;
	}

	system("clear");
	printf("\t____________~<>~___________\n");
	printf("\tProduto não encontrado\n");	//se o produto não existir, retornará a própria lista
	printf("\tAperte 1 para voltar: ");
	scanf("%d", &volta);
	return l;
}

void display(tp_nodo *l){
	tp_nodo *p;
	int volta;
	
	system("clear");

	
	printf("\t___________~<>~__________\n");

	for(p = l; p != NULL; p = p->prox){ //p é igual a l e percorre até achar um nodo NULL, p vai apontando pro proximo da l
		printf("\tCódigo do produto: %d\n", (p->produto).codigo);
		printf("\tNome: %s", (p->produto).nome);
		printf("\tPreço: %.2f", (p->produto).preco);
		printf("\n\n");
	}

	if(vazia(l)) { //se a função vazia for verdadeira retorna a lista
		system("clear");
		printf("\t___________~<>~__________\n");
		printf("\tLista vazia.\n");
	}
	printf("\t___________~<>~__________\n");
	printf("\tAperte 1 para voltar: ");
	scanf("%d", &volta);
}

void libera(tp_nodo *l){
	free(l);
}

int main(void){
	int op;
	tp_nodo *l = cria(); //cria uma lista vazia
	
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
			case 1: l = push(l); break;
			case 2: l = pop(l); break;
			case 3: display(l); break;

		}
	
	} while(op != 0);

	libera(l);
	
	return 0;
}
