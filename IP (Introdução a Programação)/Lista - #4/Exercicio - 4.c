#include <stdio.h>

void preencherVetor(int tamanho, int vetor[], char nomeVetor) {
    printf("Preenchendo o vetor %c:\n", nomeVetor);
    for (int i = 0; i < tamanho; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }
}

void encontrarRepetidos(int tamanho1, int vetor1[], int tamanho2, int vetor2[]) {
    printf("\nElementos encontrados no vetor 1 que estao no vetor 2:\n");
    for (int i = 0; i < tamanho1; i++) {
        int encontrado = 0;
        for (int j = 0; j < i; j++) {
            if (vetor1[j] == vetor1[i]) {
                encontrado = 1;
                break;
            }
        }

        if (encontrado) {
            continue;
        }

        for (int j = 0; j < tamanho2; j++) {
            if (vetor2[j] == vetor1[i]) {
                printf("%d\n", vetor1[i]);
                break;
            }
        }
    }
}

int main() {
    int tamanhoVetor1, tamanhoVetor2;
    int vetor1[20], vetor2[20];

    printf("Digite o tamanho do vetor 1 (maximo %d): ", 20);
    scanf("%d", &tamanhoVetor1);

    if (tamanhoVetor1 <= 0 || tamanhoVetor1 > 20) {
        printf("Tamanho do vetor 1 invalido!\n");
        return 1;
    }

    printf("Digite o tamanho do vetor 2 (maximo %d): ", 20);
    scanf("%d", &tamanhoVetor2);

    if (tamanhoVetor2 <= 0 || tamanhoVetor2 > 20) {
        printf("Tamanho do vetor 2 invalido!\n");
        return 1;
    }

    preencherVetor(tamanhoVetor1, vetor1, '1');
    preencherVetor(tamanhoVetor2, vetor2, '2');

    encontrarRepetidos(tamanhoVetor1, vetor1, tamanhoVetor2, vetor2);

    return 0;
}