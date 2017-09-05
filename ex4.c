/*Crie uma função que receba como parâmetros dois vetores de inteiros, v1 e v2, e as suas
respectivas quantidades de elementos, n1 e n2. A função deverá retornar um ponteiro para
um terceiro vetor, v3, com capacidade para (n1 + n2) elementos, alocado dinamicamente,
contendo a união de v1 e v2.
Por exemplo, se v1 = {11, 13, 45, 7} e v2 = {24, 4, 16, 81, 10, 12}, v3 irá conter {11, 13,
45, 7, 24, 4, 16, 81, 10, 12}.
O cabeçalho dessa função deverá ser o seguinte:
int* uniao(int *v1, int n1, int *v2, int n2);
Em seguida, crie a função principal do programa para chamar a função união passando dois
vetores informados pelo usuário (ou declarados estaticamente). Em seguida, o programa
deve exibir na tela os elementos do vetor resultante. Não esqueça de liberar a memória
alocada dinamicamente.*/

#include <stdio.h>
#include <stdlib.h>

int *uniao(int *v1, int n1, int *v2, int n2){
	
	int *v3, n3, i, j;

	n3 = n1 + n2;

	v3 = (int*)calloc(n3, sizeof(int));

	for(i = 0; i < n1; i++)
		*(v3 + i) = *(v1 + i);
	
	for(i = n1, j = 0; i < n2 + n1; i++, j++)
		*(v3 + i) = *(v2 + j);

	return v3;
}

int main(void){
	
	int *v1, n1, *v2, n2, i, *v3;

	printf("\nDigite a quantidade de números do 1º vetor: ");
	scanf("%d", &n1);
	printf("\nDigite a quantidade de números do 2º vetor: ");
	scanf("%d", &n2);

	v1 = (int*)calloc(n1, sizeof(int));
	v2 = (int*)calloc(n2, sizeof(int));

	printf("\n\nDigite os elementos do 1º vetor:\n");
	
	for(i = 0; i < n1; i++){
		printf("\nDigite o conteúdo da %dª posição: ", i+1);
		scanf("%d", v1 + i);
	}
	
	printf("\n\nDigite os elementos do 2º vetor:\n");
	
	for(i = 0; i < n2; i++){
		printf("\nDigite o conteúdo da %dª posição: ", i+1);
		scanf("%d", v2 + i);
	}

	v3 = uniao(v1, n1, v2, n2);

	printf("\n\n");
	
	for(i = 0; i < n1 + n2; i++){
		printf("Conteúdo da %dª posição:%d\n\n", i + 1, *(v3 + i));
	}
	
	free(v1);
	free(v2);
	free(v3);

	return 0;
}