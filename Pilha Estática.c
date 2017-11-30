/*************************
  UFFS CHAPECÓ
  github.com/barbs-pm
  Barbara Pegoraro Markus
  
    PILHA ESTÁTICA
**************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct _pilha{
	int info[MAX];
	int topo;
} Tipo_pilha;

void ast(int j){ // função para colocar asteriscos 
	int i;
	if(j) system("clear");
	printf("\n");
	for(i = 0; i < 29; i++)
		printf("*");
	printf("\n");
}

int verificador(Tipo_pilha *p){
	printf("Topo é: %d\n", p->topo);

	if(p->topo == -1) //pilha vazia
		return 1;

	if(p->topo == 4) //pilha cheia
		return 0;
	
	else return 2;
}

void push(Tipo_pilha *p){
	char volta[5];

	if(!verificador(p)){ 
		printf("Pilha cheia. Deseja voltar?\n");
		scanf("%s", volta);
	}
	else{ 
		printf("Adicione o elemento: ");
		p->topo++;
		scanf("%d", p->info + p->topo);
	}
}

void pop(Tipo_pilha *p){ //desempilhar
	int volta;

	if(verificador(p) == 1) {
		printf("Pilha vazia. Deseja voltar?: ");
		scanf("%d", &volta);
	}
	else{
		p->topo--;
	}
}

void display(Tipo_pilha *p){
	int i;
	char escolha[5];

	ast(1);

	for(i = p->topo; i >= 0; i--){
		printf("(%d°) elemento : %d\n", i, *(p->info + i));
	}
	ast(0);
	printf("Deseja voltar? ");
	scanf("%s", escolha);

}

void destruir(Tipo_pilha *p){
	free(p);
}

int main(void){
	int op;
	Tipo_pilha *p;
	
	p = (Tipo_pilha*) malloc(sizeof(Tipo_pilha));
	
	p->topo = -1;

	do{
		ast(1);
		printf("\tPILHA:\n\n");
		printf("(1) Empilhar elemento\n");
		printf("(2) Desempilhar elemento\n");
		printf("(3) Exibir pilha\n");
		printf("(4) Destruir pilha (sair)\n");
		ast(0);
		printf("Entre com a sua opção: ");
		scanf("%d", &op);

		switch(op){
			case 1: push(p); break;
			case 2: pop(p); break;
			case 3: display(p); break;
			case 4: destruir(p); break;
			default: printf("Opção inválida\n");
		}

	} while(op != 4);
}
