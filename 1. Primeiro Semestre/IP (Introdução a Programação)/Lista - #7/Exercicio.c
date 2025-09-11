#include <stdio.h>

void ordenarBubbleSort(int vetor[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

int buscaBinaria(int vetor[], int n, int x) {
    int esquerda = 0, direita = n - 1;
    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        if (vetor[meio] == x) {
            return meio;
        }

        if (vetor[meio] < x) {
            esquerda = meio + 1;
        }

        else {
            direita = meio - 1;
        }
    }

    return -1;
}

int main() {
    int vetor[30];
    int contagem = 0;
    int numero;

    printf("Digite numeros (maximo 30):\n");
    while (contagem < 30) {
        printf("Digite um numero: ");
        scanf("%d", &numero);
        vetor[contagem] = numero;
        contagem++;

        ordenarBubbleSort(vetor, contagem);

        printf("Vetor ordenado: ");
        for (int i = 0; i < contagem; i++) {
            printf("%d ", vetor[i]);
        }
        printf("\n");

        char opcao;
        if (contagem < 30) {
            printf("Deseja inserir um novo numero (s/n)? ");
            scanf(" %c", &opcao);
            if (opcao == 'n' || opcao == 'N') {
                break;
            }
        }
    }

    printf("Digite um numero para buscar no vetor: ");
    scanf("%d", &numero);
    int resultado = buscaBinaria(vetor, contagem, numero);

    if (resultado != -1) {
        printf("Numero %d encontrado na posicao %d\n", numero, resultado);
    } else {
        printf("Numero %d nao encontrado\n", numero);
    }

    return 0;
}