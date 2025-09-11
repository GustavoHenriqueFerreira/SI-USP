#include <stdio.h>

void insercaoValoresTamanhoVetor(int tamanho, int vetor[]) {
    printf("Digite os elementos do vetor (insira um valor negativo para parar):\n");
    for (int i = 0; i < tamanho; i++) {
        int temp;
        printf("Elemento %d: ", i + 1);
        scanf("%d", &temp);

        if (temp < 0) {
            tamanho = i;
            break; 
        } else {
            vetor[i] = temp;
        }
    }

    int maior = vetor[0], menor = vetor[0], soma = 0;
    int posicaoMaior = 0, posicaoMenor = 0;

    for (int i = 0; i < tamanho; i++) {
        soma += vetor[i];

        if (vetor[i] > maior) {
            maior = vetor[i];
            posicaoMaior = i;
        }

        if (vetor[i] < menor) {
            menor = vetor[i];
            posicaoMenor = i;
        }
    }

    printf("\nResultados:\n");
    printf("Maior valor: %d (posicao %d)\n", maior, posicaoMaior + 1);
    printf("Menor valor: %d (posicao %d)\n", menor, posicaoMenor + 1);
    printf("Soma de valores: %d\n", soma);
    printf("Media de valores: %.2f\n", (float)soma / tamanho);
}

void encontrarRepeticoes(int x, int tamanho, int vetor[]) {
    int numeroRepeticoes = 0;
    printf("\nRepeticoes do valor %d na/nas posicao/posicoes: ", x);
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == x) {
            printf("%d ", i + 1);
            numeroRepeticoes++;
        }
    }
    printf("\nTotal de repeticoes: %d\n", numeroRepeticoes);
}

int main() {
    int tamanhoVetor;

    printf("Digite o tamanho do vetor (maximo 20): ");
    scanf("%d", &tamanhoVetor);

    if (tamanhoVetor <= 0 || tamanhoVetor > 20) {
        printf("Tamanho invalido!\n");
        return 1;
    }

    int vetor[tamanhoVetor];

    insercaoValoresTamanhoVetor(tamanhoVetor, vetor);

    int x;
    printf("\nDigite o valor que deseja encontrar no vetor: ");
    scanf("%d", &x);

    encontrarRepeticoes(x, tamanhoVetor, vetor);

    return 0;
}