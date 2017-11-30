/*************************
  UFFS CHAPECÓ
  github.com/barbs-pm
  Barbara Pegoraro Markus
  
     INSERTION SORT
**************************/

#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

void insertion (int vet[], int n){
  int i, j, atual;
  for(i = 0; i < n; i++){
    atual = vet[i];
    for(j = i - 1; j >= 0 && vet[j] > atual; j--){
      vet[j+1] = vet[j];
    }
    vet[j+1] = atual;
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

  insertion(vet, num);

  printf("Vetor ordenado: ");
  for(i = 0; i < num; i++)
  	printf("%d ", vet[i]);

}
