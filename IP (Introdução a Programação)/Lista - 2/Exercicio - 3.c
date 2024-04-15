#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	 int N = 0, desejaSair = 0, divisivelQuatro = 0, divisivelSete = 0, divisivelTreze = 0;
	 
	  do {
        printf("Digite a quantidade de numeros a serem digitados (deve ser maior que 0): ");
        scanf("%d", &N);

        if (N <= 0) {
            printf("Numero deve ser maior que 0. Tente novamente.\n");
        }
    } while (N <= 0);
	 
	 while(desejaSair == 0){
     	if (N % 4 == 0) {
     		divisivelQuatro++; 
		};
		
		if (N % 7 == 0) {
     		divisivelSete++; 
		};
		
		if (N % 13 == 0) {
     		divisivelTreze++; 
		};
     	
     	printf("Deseja sair (digite 1 para sair): ");
     	scanf("%d", &desejaSair);
     	
     	if(desejaSair == 0){
     		printf("Digite um numero inteiro positivo:");	
     		scanf("%d", &N);
		}
	 };
	

  	printf("\n Divisivel quatro = %d\n", divisivelQuatro);
  	printf("\n Divisivel sete = %d\n", divisivelSete);
  	printf("\n Divisivel treze = %d\n", divisivelTreze);
	 	
	return 0;
}