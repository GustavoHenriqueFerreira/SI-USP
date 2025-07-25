#include <stdio.h>
#include <limits.h>

#define MAX 10

void inserirElementos(int matriz[MAX][MAX], int linhas, int colunas);
void mostrarMaiorElementoLinha(int matriz[MAX][MAX], int linhas, int colunas);
void mostrarMaiorElementoColuna(int matriz[MAX][MAX], int linhas, int colunas);
void mostrarMenorElementoLinha(int matriz[MAX][MAX], int linhas, int colunas);
void mostrarMenorElementoColuna(int matriz[MAX][MAX], int linhas, int colunas);
void mostrarPosicaoMaiorElemento(int matriz[MAX][MAX], int linhas, int colunas);
void mostrarPosicaoMenorElemento(int matriz[MAX][MAX], int linhas, int colunas);
void mostrarSomaLinha(int matriz[MAX][MAX], int linhas, int colunas);
void mostrarSomaColuna(int matriz[MAX][MAX], int linhas, int colunas);
void mostrarLinhaMaiorSoma(int matriz[MAX][MAX], int linhas, int colunas);
void mostrarColunaMaiorSoma(int matriz[MAX][MAX], int linhas, int colunas);
void multiplicarMatrizes(int matA[MAX][MAX], int matB[MAX][MAX], int matC[MAX][MAX], int linhasA, int colunasA, int colunasB);

int main() {
    int matriz[MAX][MAX];
    int linhas, colunas;

    printf("Digite o numero de linhas (max 10): ");
    scanf("%d", &linhas);
    printf("Digite o numero de colunas (max 10): ");
    scanf("%d", &colunas);

    inserirElementos(matriz, linhas, colunas);

    mostrarMaiorElementoLinha(matriz, linhas, colunas);
    mostrarMaiorElementoColuna(matriz, linhas, colunas);
    mostrarMenorElementoLinha(matriz, linhas, colunas);
    mostrarMenorElementoColuna(matriz, linhas, colunas);
    mostrarPosicaoMaiorElemento(matriz, linhas, colunas);
    mostrarPosicaoMenorElemento(matriz, linhas, colunas);
    mostrarSomaLinha(matriz, linhas, colunas);
    mostrarSomaColuna(matriz, linhas, colunas);
    mostrarLinhaMaiorSoma(matriz, linhas, colunas);
    mostrarColunaMaiorSoma(matriz, linhas, colunas);

    // DESAFIO: Multiplicação de matrizes
    int matA[MAX][MAX], matB[MAX][MAX], matC[MAX][MAX];
    int linhasA, colunasA, linhasB, colunasB;

    printf("\nDesafio: Multiplicação de Matrizes\n");
    printf("Digite o numero de linhas da matA (max 10): ");
    scanf("%d", &linhasA);
    printf("Digite o numero de colunas da matA e numero de linhas da matB (max 10): ");
    scanf("%d", &colunasA);
    linhasB = colunasA; // Para multiplicação, o número de colunas de A deve ser igual ao número de linhas de B
    printf("Digite o numero de colunas da matB (max 10): ");
    scanf("%d", &colunasB);

    printf("Inserindo elementos na matA:\n");
    inserirElementos(matA, linhasA, colunasA);
    printf("Inserindo elementos na matB:\n");
    inserirElementos(matB, linhasB, colunasB);

    multiplicarMatrizes(matA, matB, matC, linhasA, colunasA, colunasB);

    printf("Resultado da multiplicacao (matC = matA x matB):\n");
    
    for(int i = 0; i < linhasA; i++) {
        for(int j = 0; j < colunasB; j++) {
            printf("%d ", matC[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void inserirElementos(int matriz[MAX][MAX], int linhas, int colunas) {
    printf("Insira os elementos da matriz (%dx%d):\n", linhas, colunas);
    
    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            while (scanf("%d", &matriz[i][j]) != 1) {
                printf("Entrada inválida. Insira um número inteiro para o elemento [%d][%d]: ", i, j);
                while (getchar() != '\n'); // Limpar o buffer de entrada
            }
        }
    }
}

void mostrarMaiorElementoLinha(int matriz[MAX][MAX], int linhas, int colunas) {
    for(int i = 0; i < linhas; i++) {
        int maior = matriz[i][0];
        for(int j = 1; j < colunas; j++) {
            if(matriz[i][j] > maior) {
                maior = matriz[i][j];
            }
        }

        printf("Maior elemento da linha %d: %d\n", i, maior);
    }
}

void mostrarMaiorElementoColuna(int matriz[MAX][MAX], int linhas, int colunas) {
    for(int j = 0; j < colunas; j++) {
        int maior = matriz[0][j];
        for(int i = 1; i < linhas; i++) {
            if(matriz[i][j] > maior) {
                maior = matriz[i][j];
            }
        }

        printf("Maior elemento da coluna %d: %d\n", j, maior);
    }
}

void mostrarMenorElementoLinha(int matriz[MAX][MAX], int linhas, int colunas) {
    for(int i = 0; i < linhas; i++) {
        int menor = matriz[i][0];
        for(int j = 1; j < colunas; j++) {
            if(matriz[i][j] < menor) {
                menor = matriz[i][j];
            }
        }

        printf("Menor elemento da linha %d: %d\n", i, menor);
    }
}

void mostrarMenorElementoColuna(int matriz[MAX][MAX], int linhas, int colunas) {
    for(int j = 0; j < colunas; j++) {
        int menor = matriz[0][j];
        for(int i = 1; i < linhas; i++) {
            if(matriz[i][j] < menor) {
                menor = matriz[i][j];
            }
        }

        printf("Menor elemento da coluna %d: %d\n", j, menor);
    }
}

void mostrarPosicaoMaiorElemento(int matriz[MAX][MAX], int linhas, int colunas) {
    int maior = matriz[0][0];
    int linhaMaior = 0, colunaMaior = 0;

    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            if(matriz[i][j] > maior) {
                maior = matriz[i][j];
                linhaMaior = i;
                colunaMaior = j;
            }
        }
    }

    printf("Maior elemento da matriz esta na linha %d, coluna %d\n", linhaMaior, colunaMaior);
}

void mostrarPosicaoMenorElemento(int matriz[MAX][MAX], int linhas, int colunas) {
    int menor = matriz[0][0];
    int linhaMenor = 0, colunaMenor = 0;

    for(int i = 0; i < linhas; i++) {
        for(int j = 0; j < colunas; j++) {
            if(matriz[i][j] < menor) {
                menor = matriz[i][j];
                linhaMenor = i;
                colunaMenor = j;
            }
        }
    }

    printf("Menor elemento da matriz esta na linha %d, coluna %d\n", linhaMenor, colunaMenor);
}

void mostrarSomaLinha(int matriz[MAX][MAX], int linhas, int colunas) {
    for(int i = 0; i < linhas; i++) {
        int soma = 0;

        for(int j = 0; j < colunas; j++) {
            soma += matriz[i][j];
        }

        printf("Soma dos valores da linha %d: %d\n", i, soma);
    }
}

void mostrarSomaColuna(int matriz[MAX][MAX], int linhas, int colunas) {
    for(int j = 0; j < colunas; j++) {
        int soma = 0;

        for(int i = 0; i < linhas; i++) {
            soma += matriz[i][j];
        }

        printf("Soma dos valores da coluna %d: %d\n", j, soma);
    }
}

void mostrarLinhaMaiorSoma(int matriz[MAX][MAX], int linhas, int colunas) {
    int maiorSoma = 0;
    int linhaMaiorSoma = 0;

    for (int i = 0; i < linhas; i++) {
        int soma = 0;

        for (int j = 0; j < colunas; j++) {
            soma += matriz[i][j];
        }

        if (soma > maiorSoma) {
            maiorSoma = soma;
            linhaMaiorSoma = i;
        }
    }

    printf("Linha com maior soma dos valores: %d\n", linhaMaiorSoma);
}

void mostrarColunaMaiorSoma(int matriz[MAX][MAX], int linhas, int colunas) {
    int maiorSoma = 0;
    int colunaMaiorSoma = 0;

    for (int j = 0; j < colunas; j++) {
        int soma = 0;

        for (int i = 0; i < linhas; i++) {
            soma += matriz[i][j];
        }

        if (soma > maiorSoma) {
            maiorSoma = soma;
            colunaMaiorSoma = j;
        }
    }

    printf("Coluna com maior soma dos valores: %d\n", colunaMaiorSoma);
}

void multiplicarMatrizes(int matA[MAX][MAX], int matB[MAX][MAX], int matC[MAX][MAX], int linhasA, int colunasA, int colunasB) {
    for(int i = 0; i < linhasA; i++) {
        for(int j = 0; j < colunasB; j++) {
            matC[i][j] = 0;
            for(int k = 0; k < colunasA; k++) {
                matC[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
}
