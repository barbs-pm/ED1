/*************************
  UFFS CHAPECÓ
  github.com/barbs-pm
  Barbara Pegoraro Markus
  
    SELECTION SORT
**************************/

#include <stdio.h>
#include <stdlib.h>

void selection(int vet[], int n){ 
	int i, j, menor, aux;
	for (i = 0; i < (n-1); i++){
  		menor = i;
    	for (j = (i+1); j < n; j++) //procura o menor elemento do vetor
      		if(vet[j] < vet[menor]) 
        		menor = j;
  
     	if (vet[i] != vet[menor]){ //troca com o menor elemento do vetor
       		aux = vet[i];
       		vet[i] = vet[menor];
       		vet[menor] = aux;
     	}
  	}
}

int main(void){
    int i, j, aux, num, *vet;

    printf("Digite quantos numeros deseja ordenar: ");
  	scanf("%d", &num);

  	vet = (int*) calloc(num, sizeof(int));

  	printf("Digite os valores: \n");
  	for(i = 0; i < num; i++)
  		scanf("%d", vet + i);

  	selection(vet, num);

  	printf("Vetor ordenado: ");
  	for(i = 0; i < num; i++)
  		printf("%d ", vet[i]);

 }
