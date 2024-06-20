#include <stdio.h>

int main() {
    int N;
    float numero, maior, menor, soma = 0.0, media;

    printf("Digite a quantidade de numeros: ");
    scanf("%d", &N);

    if (N <= 0) {
        printf("Quantidade invalida!\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%f", &numero);
        
        if (i == 0) {
            maior = menor = numero;
        } else {
            if (numero > maior) {
                maior = numero;
            }
            if (numero < menor) {
                menor = numero;
            }
        }

        soma += numero;
    }

    media = soma / N;

    printf("Maior numero: %.2f\n", maior);
    printf("Menor numero: %.2f\n", menor);
    printf("Media dos numeros: %.2f\n", media);

    return 0;
}