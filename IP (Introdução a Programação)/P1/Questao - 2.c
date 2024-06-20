#include <stdio.h>

void decimalParaBinario(int N) {
    int resto;
    char binario[32];
    int indice = 0;

    if (N == 0) {
        printf("A representacao binaria de N e: 0\n");
        return;
    }

    while (N > 0) {
        resto = N % 2;
        binario[indice++] = '0' + resto;
        N = N / 2;
    }

    printf("A representacao binaria de N e: ");
    for (int i = indice - 1; i >= 0; i--) {
        printf("%c", binario[i]);
    }
    printf("\n");
}

int main() {
    int N;

    printf("Digite um numero inteiro N maior ou igual a 0: ");
    scanf("%d", &N);

    decimalParaBinario(N);

    return 0;
}