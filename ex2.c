/*Altere o programa para armazenar uma estrutura em 
cada posição do vetor.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char nome[50];
	char endereco[100];
	int matricula;
} estudante;

int main(void){
	int num, i;

	system("clear");
	printf("\nDigite o número de posições do vetor: ");
	scanf("%d", &num);
	
	estudante *p;

	p = (estudante*)(malloc(num * sizeof(estudante)));
	// p é endereço ((p+i) também é)
	// *p é o conteudo para oq ele ta apontando (pode manipular os valores)

	printf("\nIndique o conteúdo das posições:\n ");

	for(i = 0; i < num; i++){
		printf("\n\t%dª posição\n", i+1);
		printf("Nome: "); 
		__fpurge(stdin); 
		fgets((p+i)->nome, 50, stdin);
		printf("Endereço: "); 
		__fpurge(stdin); 
		fgets((p+i)->endereco, 100, stdin);
		printf("Matrícula: "); 
		__fpurge(stdin); 
		scanf("%d", &(p+i)->matricula);
	}

	printf("\n");
	system("clear");

	for(i = 0; i < num; i++){
		printf("\n\t%dª posição\n", i+1);
		printf("Nome: %s", (p+i)->nome);
		printf("Endereço: %s", (p+i)->endereco);
		printf("Matrícula: %d\n", (p+i)->matricula);
	}

	free(p);	
	
	return 0;
}
