/*************************
  UFFS CHAPECÓ
  github: barbs-pm
  Barbara Pegoraro Markus
**************************/

/*Implemente um programa, para alocar memória para um 
vetor. O número de posições do vetor será indicado via 
teclado, assim como o conteúdo das posições. Após a 
atribuição de valores às posições do vetor, o programa 
deve imprimir(na tela) as posições e seus conteúdos.*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
	int num, *p, i;
	
	system("clear");
	printf("\nDigite o número de posições do vetor: ");
	scanf("%d", &num);

	p = (int*)calloc(num, sizeof(int));

	printf("\nIndique o conteúdo das posições:\n ");

	for(i = 0; i < num; i++){
		printf("\nDigite o conteúdo da %dª posição: ", i+1);
		scanf("%d", p + i);
	}

	printf("\n");

	for(i = 0; i < num; i++)
		printf("\nConteúdo da %dª posição: %d\n", i+1, *(p + i));

	
	free(p);

	return 0;
}
