#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void verificarRepeticoesNumero(int numero, int digitoProcurado) {
    int repeticoes = 0;

    while (numero >= 10) {
        int ultimoDigitoNumero = numero % 10;
        
        numero = numero / 10;

        int penultimoDigitoNumero = numero % 10;

        if (ultimoDigitoNumero == penultimoDigitoNumero && ultimoDigitoNumero == digitoProcurado) {
            repeticoes++;
        };
    }

    if (repeticoes != 0) {
        printf("Numero de repeticoes: %d\n", repeticoes);
    } else {
        printf("Nao ha repeticoes");
    }
}

int main(int argc, char const *argv[])
{
    int numero, digito;

    do {
    printf("Digite o numero inteiro positivo para verificar repeticoes nele: ");
    scanf("%d", &numero);
    } while (numero <= 0);

    printf("Digite o digito de um unico digito: ");
    scanf("%d", &digito);

    verificarRepeticoesNumero(numero, digito);

    return 0;
}