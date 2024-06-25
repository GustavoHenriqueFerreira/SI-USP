#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node* proximo;
};

struct Node* criarNode(int info) {
    struct Node* novoNode = (struct Node*)malloc(sizeof(struct Node));

    novoNode->info = info;
    novoNode->proximo = NULL;

    return novoNode;
}

void adicionarNode(struct Node** cabeca, int novoInfo) {
    struct Node* novoNode = criarNode(novoInfo);
    struct Node* ultimo = *cabeca;

    if (*cabeca == NULL) {
        *cabeca = novoNode;
        return;
    }

    while (ultimo->proximo != NULL) {
        ultimo = ultimo->proximo;
    }

    ultimo->proximo = novoNode;
}

struct Node* criarListaLigadaComMatriz(int matriz[5][5]) {
    struct Node* cabeca = NULL;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            adicionarNode(&cabeca, matriz[i][j]);
        }
    }

    return cabeca;
}

void imprimirListaLigada(struct Node* no) {
    while (no != NULL) {
        printf("%02d -> ", no->info);
        no = no->proximo;
    }

    printf("<<NULL>>\n");
}

int main() {
    int matriz [5][5] = {
        { 1, 2, 3, 4, 5 },
        { 6, 7, 8, 9, 10 },
        { 11, 12, 13, 14, 15 },
        { 16, 17, 18, 19, 20 },
        { 21, 22, 23, 24, 25 }
    };

    struct Node* listaLigada = criarListaLigadaComMatriz(matriz);
    imprimirListaLigada(listaLigada);

    return 0;
}