#include <stdio.h>

void inserirValores(int vetor[], int tamanho, const char *nome) {
    for (int i = 0; i < tamanho; i++) {
        printf("Digite o valor para %s de posicao %d: ", nome, i + 1);
        scanf("%d", &vetor[i]);
    }
}

void listarValores(int vetor[], int tamanho, const char *nome) {
    printf("%s: ", nome);
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int primeiroVetor[10], segundoVetor[10], VetorMenores[10], VetorMaiores[10];
    int tamanho = 10;

    inserirValores(primeiroVetor, tamanho, "Primeiro vetor");
    inserirValores(segundoVetor, tamanho, "Segundo vetor");

    for (int i = 0; i < tamanho; i++) {
        if (primeiroVetor[i] < segundoVetor[i]) {
            VetorMenores[i] = primeiroVetor[i];
            VetorMaiores[i] = segundoVetor[i];
        } else {
            VetorMenores[i] = segundoVetor[i];
            VetorMaiores[i] = primeiroVetor[i];
        }
    }

    listarValores(VetorMenores, tamanho, "Vetor de Menores Valores");
    listarValores(VetorMaiores, tamanho, "Vetor de Maiores Valores");

    return 0;
}