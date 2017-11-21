/*************************
  UFFS CHAPECÓ
  github: barbs-pm
  Barbara Pegoraro Markus
	
	  BUSCA BINÁRIA
**************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int PesquisaBinaria (int v[], int elementinho, int inicio, int fim){
    int meio = (inicio+fim)/2;

    if(elementinho == v[meio]) //elementinho é igual ao elemento do meio, não precisa mais procurar
        return meio; //retorna a posição que esta o elementinho
    
    else if(inicio >= fim)
        meio = -1;
    
    else if (elementinho < v[meio]) //se o elementinho é menor que o elemento meio significa que ele ta na parte esquerda da lista
        meio = PesquisaBinaria(v, elementinho, inicio, meio-1); //vai recalcular o meio e pesquisar nessa metade da lista
    
    else if(elementinho > v[meio])	//se o elementinho é maior que o elemento meio significa que ele ta na parte direita da lista
        meio = PesquisaBinaria(v, elementinho, meio+1, fim); //vai recalcular o meio e pesquisar nessa metade da lista
    													
    return meio; //retorna a posição que esta o elementinho
}

void insertionSort(int vet[10]) {
	int i, j, atual;

	for (i = 1; i < 10; i++) {
		atual = vet[i];
		
		for (j = i - 1; (j >= 0) && (atual < vet[j]); j--)
			vet[j + 1] = vet[j];
        
		vet[j+1] = atual;
	}
}

void push(int vet[10]){
	printf("\t____________~<>~___________\n");
	printf("\tComplete o vetor:\n");
	for(int i = 0; i < 10; i++){
		printf("\t");
		scanf("%d", &vet[i]);
	}		
	insertionSort(vet);
}

int main(){
	int vet[10]={0}, i, elementinho, posicao;
	system("clear");

	push(vet);
    printf("\t____________~<>~___________\n\t");

	for(i = 0; i < 10; i++) 
		printf("%i ",vet[i]);

    printf("\n");
	printf("\tEscolha um elemento acima para buscar: ");
	scanf("%i", &elementinho);

    posicao = PesquisaBinaria(vet,elementinho,0,9);
    
    if(posicao == -1) printf("\tNão encontrado\n");
    else printf("\tEncontrado na posição %i do vetor\n", posicao);

	return 0;
}