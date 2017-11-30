/*************************
  UFFS CHAPECÓ
  github.com/barbs-pm
  Barbara Pegoraro Markus
  
     PILHA DINÂMICA
**************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#define TAM 50

typedef struct _produto{//criação de uma struct tipo produto
	int cod;
	char nome[TAM];
	float preco;
}Tipo_produto;

typedef struct _pilha{//criação de uma struct tipo pilha
	Tipo_produto *info;
	int topo;
}Tipo_pilha;

void ast(int j){ // função para colocar asteriscos 
	int i;
	if(j) system("clear");
	printf("\n");
	for(i = 0; i < 39; i++)
		printf("*");
	printf("\n");
}

int verificador(Tipo_pilha *p, int qtd){
	if(p->topo == -1) //pilha vazia
		return 1;

	if(p->topo == qtd - 1) //pilha cheia
		return 0;
	
	else return 2;
}

void push(Tipo_pilha *p, int qtd){
	char volta[5];

	if(!verificador(p, qtd)){ 
		printf("Pilha cheia. Deseja voltar?\n");
		scanf("%s", volta);
	}
	else{ 
		p->topo++;
		ast(1);
		printf("Código do produto: ");
		scanf("%d", &(p->info + p->topo)->cod);
		printf("Preço: ");
		scanf("%f", &(p->info + p->topo)->preco);
		printf("Nome: ");
		getchar();
		fgets((p->info + p->topo)->nome, TAM, stdin);
	}
}

void pop(Tipo_pilha *p, int qtd){ //desempilhar
	char volta[5];

	if(verificador(p, qtd) == 1) {
		printf("Pilha vazia. Deseja voltar?: ");
		scanf("%s", volta);
	}
	else{
		p->topo--;
	}
}

void display(Tipo_pilha *p, int qtd){
	int i;
	char escolha[5];

	ast(1);

	for(i = p->topo; i >= 0; i--){
		printf("\t(%d°) Produto\n\n", i+1);
		printf("Código: %d\n", ((p->info + i)->cod));
		printf("Nome: %s", ((p->info + i)->nome));
		printf("Preço: R$ %.2f\n", ((p->info + i)->preco));
		printf("\n\n");
	}
	ast(0);
	printf("Deseja voltar? ");
	scanf("%s", escolha);

}

void destruir(Tipo_pilha *p, int qtd){
	free(p);
}

int main(void){
	int op, qtd;
	Tipo_pilha *p;
	
	p = (Tipo_pilha*) malloc(sizeof(Tipo_pilha));
	
	p->topo = -1;
	
	ast(1);
	printf("Antes de mais nada...\nDeseja adicionar quantos elementos?");
	ast(0);
	printf("Entre com a sua opção: ");
	scanf("%d", &qtd);

	p->info = (Tipo_produto*)malloc(qtd * sizeof(Tipo_produto));

	do{
		
		ast(1);
		printf("\tPILHA:\n\n");
		printf("(1) Adicionar produto\n");
		printf("(2) Remover produto\n");
		printf("(3) Exibir lista de produtos\n");
		printf("(4) DESTRUIR PILHA (sair)\n");
		ast(0);
		printf("Entre com a sua opção: ");
		scanf("%d", &op);

		switch(op){
			case 1: push(p, qtd); break;
			case 2: pop(p, qtd); break;
			case 3: display(p, qtd); break;
			case 4: destruir(p, qtd); break;
			default: printf("Opção inválida\n");
		}

	} while(op != 4);
}
