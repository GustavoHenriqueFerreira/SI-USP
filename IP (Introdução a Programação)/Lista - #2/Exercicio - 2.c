#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char *argv[]) {
    int N, unidade, dezena, centena, milhar;

    printf("Digite um numero positivo e menor que 10000: ");
    scanf("%d", &N);

    if (N < 0 || N >= 10000) {
        printf("Acima de 10000\n");
        return 1;
    }

    printf("Unidade: %d\n", N % 10);
    printf("Dezena: %d\n", (N / 10) % 10);
    printf("Centena: %d\n", (N / 100) % 10);
    printf("Milhar: %d\n", (N / 1000) % 10);

    return 0;
}