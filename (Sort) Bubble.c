/*************************
  UFFS CHAPECÓ
  github.com/barbs-pm
  Barbara Pegoraro Markus
 
      BUBBLE SORT
**************************/

#include <stdio.h>
#include <stdlib.h>

void bubble(int vet[], int n){
	for(i = 0; i < n - 1; i++){
		for(j = 0; j < (n - 1) - c; j++){
			if(vet[j] > vet[j+1] ){
				aux = vet[j];
				vet[j] = vet[j+1];
				vet[j+1] = aux;
			}
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

  	bubble(vet, num);

  	printf("Vetor ordenado: ");
  	for(i = 0; i < num; i++)
  		printf("%d ", vet[i]);

 }
