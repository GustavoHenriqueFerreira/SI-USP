#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
  int N, soma, digito, maiorNumero, menorNumero, contador;
  float media;
       
  printf("Digite um numero inteiro positivo: ");
  scanf("%d", &N);

  if(N <= 0) {
    printf("Numero negativo ou zero");
    return 1;
  }

  soma = N;
  menorNumero = N;
  maiorNumero = N;
  contador = 1;
  
  while (N > 0){
  	printf("Digite um numero inteiro positivo: ");
  	scanf("%d", &N);
  	
	if(N > 0){
  		if(maiorNumero < N){
  			maiorNumero = N;		
			};
	
		if(menorNumero > N){
  			menorNumero = N;		
		};
  		
        soma = soma + N;
        contador++;
        media = (float)soma / contador;
    }
  };
  
  printf("\n Soma dos digitos do numero dado = %d\n", soma);
  printf("\n Media = %.2f\n", media);
  printf("\n Maior Numero = %d\n", maiorNumero);
  printf("\n Menor Numero = %d\n", menorNumero);
  return 0;
}