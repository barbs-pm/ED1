/*************************
  UFFS CHAPECÓ
  github.com/barbs-pm
  Barbara Pegoraro Markus
  
     INSERTION SORT
**************************/

#include <stdio.h>
#include <stdlib.h>

int main(void){
    int i, j, aux, num, *vet;

    printf("Digite quantos numeros deseja ordenar: ");
  	scanf("%d", &num);

  	vet = (int*) calloc(num, sizeof(int));

  	printf("Digite os valores: \n");
  	for(i = 0; i < num; i++)
  		scanf("%d", vet + i);
  	
    for(i = 0; i < num; i++){
        aux = vet[i]; 
        j = i - 1; //j = antecessor de i
        while(j >= 0 && vet[j] > aux){
            vet[j+1] = vet[j];//troca de lugar com o anterior
            j--; //vai empurrando os numeros até achar o espaço que o vet[j] seja < aux (vet[i])
        }
        vet[j+1] = aux; //colocando o vetor no espaço que ficou "vazio"
    }

    printf("\nSeus números ordenados são: ");
    for(i  =0; i < num; i++)
        printf("%d ", *(vet + i));

    return 0;
}
