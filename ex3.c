/*************************
  UFFS CHAPECÓ
  github: barbs-pm
  Barbara Pegoraro Markus
**************************/

/*Altere o programa do exercício 1, de forma que receba números inteiros do usuário
indefinidamente. O programa finaliza quando o usuário entrar com o número 0.
a) Aloque, inicialmente, memória para 5 inteiros;
b) Caso o usuário entrar com mais inteiros, faça a realocação, alocando espaço para mais 5
inteiros e assim sucessivamente;*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
	int *p, i = 0, aux, aux2=0, contador=5, j;

	p = (int*)malloc(5 * sizeof(int)); //alocar 5 espaços

	printf("\nIndique o conteúdo das posições:\n ");

	do{ //preencher os espaços até ser diferente de 0
		
		printf("\nDigite o conteúdo da %dª posição: ", i+1);
		scanf("%d", (p + i));
		
		aux = *(p + i); //aux vai ser igual ao valor digitado pelo usuário
		i++;
		aux2++;
		
		if(aux2 >= 5){ //caso o usuario digite mais de 5 numeros
			aux2 = 0;
			contador += 5;
			
			int *pNew = realloc(p, contador * sizeof(int));
			printf("\n#### Realocado ####\n");
			
			if(pNew) //testar se a alocação foi bem sucedida
				p = pNew;
			
			else printf("Desculpe, problema na alocação de memória.\n");
		}	

	} while(aux != 0); 

	printf("\n\n");
	
	for(j = 0; j < i; j++){
		printf("Conteúdo da %dª posição: %d\n", j + 1, *(p + j));
	}

	free(p);

	return 0;
}
