/*****************************
   UFFS- CHAPECÓ/SC 
   BÁRBARA PEGORARO MARKUS
   CIÊNCIA DA COMPUTAÇÃO

      Insertion sort
******************************/
/**************************************************************************
O programa funciona da seguinte forma:
1) o usuario digita os dados
2) o for percorrre o vetor
3) aux recebe o vetor para não perder os dados no while
4) j recebe uma posição a menos do i
5) enquanto o j > 0 e o vetor na poisção j > aux, 
a proxima posição de j (posição i) recebe o valor do vetor
na posição j, ou seja, empurrando o maior valor para frente
e j decrementa, isso acontece até o while não encontrar nenhum valor
maior que i (aux)
6) depois que ele organizou os maiores valores, a posição j+1 (i) recebe
o aux novamente, para não perder o valor.
***************************************************************************/

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
