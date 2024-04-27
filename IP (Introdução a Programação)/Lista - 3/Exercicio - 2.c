#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int verificarPalindromo(int palindromo) {
    if (palindromo <= 0){
        printf("Numero não é positivo");
        return 0;
    }

    short int palindromoOriginal = palindromo;
    short int palindromoAoContrario = 0;

    while (palindromo > 0) {
        int unidade = palindromo % 10;
        palindromoAoContrario = palindromoAoContrario * 10 + unidade;
        palindromo = palindromo / 10;
    }

    if (palindromoOriginal == palindromoAoContrario) {
        return 1;
    } else {
        return 0;
    }
}

int main(int argc, char const *argv[])
{
    short int palindromo;
    printf("Digite um numero para verificar se e palindromo: ");
    scanf("%hd", &palindromo);

    if (verificarPalindromo(palindromo)) {
        printf("%d e um palindromo\n", palindromo);
    } else {
        printf("%d nao e um palindromo\n", palindromo);
    }

    return 0;
}