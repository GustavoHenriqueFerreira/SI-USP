#include <stdio.h>
#include <stdlib.h>

// Definição do nó da lista
typedef struct No {
    int valor;
    struct No* proximo;
} No;

// Parte A: Cria uma lista ligada simples
No* criarLista() {
    return NULL;
}

// Parte B: Inserir um elemento no início da lista
void inserirInicio(No** cabeca, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));

    novoNo->valor = valor;
    novoNo->proximo = *cabeca;

    *cabeca = novoNo;
}

// Parte C: Inserir um elemento no fim da lista
void inserirFim(No** cabeca, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));

    novoNo->valor = valor;
    novoNo->proximo = NULL;

    if (*cabeca == NULL) {
        *cabeca = novoNo;
    } else {
        No* temp = *cabeca;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novoNo;
    }
}

// Parte D: Excluir um elemento no início da lista
void excluirInicio(No** cabeca) {
    if (*cabeca != NULL) {
        No* temp = *cabeca;
        *cabeca = (*cabeca)->proximo;

        free(temp);
    }
}

// Parte E: Excluir um elemento no fim da lista
void excluirFim(No** cabeca) {
    if (*cabeca != NULL) {
        if ((*cabeca)->proximo == NULL) {
            free(*cabeca);
            *cabeca = NULL;
        } else {
            No* temp = *cabeca;
            while (temp->proximo->proximo != NULL) {
                temp = temp->proximo;
            }

            free(temp->proximo);
            temp->proximo = NULL;
        }
    }
}

// Parte F: Procurar por um elemento na lista
int procurarElemento(No* cabeca, int valor) {
    No* temp = cabeca;

    while (temp != NULL) {
        if (temp->valor == valor) {
            return 1;
        }
        temp = temp->proximo;
    }

    return 0;
}

// Função para imprimir a lista
void imprimirLista(No* cabeca) {
    No* temp = cabeca;

    while (temp != NULL) {
        printf("%d -> ", temp->valor);
        temp = temp->proximo;
    }

    printf("NULL\n");
}

// Parte G: Ordenar os elementos da lista de forma crescente
void ordenarLista(No** cabeca) {
    if (*cabeca == NULL || (*cabeca)->proximo == NULL) {
        return;
    }

    for (No* i = *cabeca; i != NULL; i = i->proximo) {
        for (No* j = i->proximo; j != NULL; j = j->proximo) {
            if (i->valor > j->valor) {
                int temp = i->valor;
                i->valor = j->valor;
                j->valor = temp;
            }
        }
    }
}

// Parte H: Inserir um elemento no meio da lista de forma ordenada
void inserirOrdenado(No** cabeca, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    if (*cabeca == NULL || (*cabeca)->valor >= valor) {
        novoNo->proximo = *cabeca;
        *cabeca = novoNo;
    } else {
        No* temp = *cabeca;
        while (temp->proximo != NULL && temp->proximo->valor < valor) {
            temp = temp->proximo;
        }
        
        novoNo->proximo = temp->proximo;
        temp->proximo = novoNo;
    }
}

// Parte G: Excluir um elemento do meio da lista
void excluirMeio(No** cabeca, int valor) {
    if (*cabeca == NULL) {
        return;
    }

    if ((*cabeca)->valor == valor) {
        No* temp = *cabeca;
        *cabeca = (*cabeca)->proximo;
        free(temp);
        return;
    }

    No* temp = *cabeca;
    while (temp->proximo != NULL && temp->proximo->valor != valor) {
        temp = temp->proximo;
    }

    if (temp->proximo == NULL) {
        return;
    }

    No* noParaExcluir = temp->proximo;
    temp->proximo = temp->proximo->proximo;
    free(noParaExcluir);
}

// Parte H: Inserir um elemento no meio da lista de forma a mantê-la ordenada (podem haver repetições de valores na lista)
void inserirOrdenadoComRepeticao(No** cabeca, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;

    if (*cabeca == NULL || (*cabeca)->valor >= valor) {
        novoNo->proximo = *cabeca;
        *cabeca = novoNo;
    } else {
        No* temp = *cabeca;
        while (temp->proximo != NULL && temp->proximo->valor < valor) {
            temp = temp->proximo;
        }
        novoNo->proximo = temp->proximo;
        temp->proximo = novoNo;
    }
}

int main() { 
    No* lista = criarLista(); // Criar lista (B)

    // Inserir elementos na lista
    inserirInicio(&lista, 3); // Inserir no início (B)
    inserirFim(&lista, 5); // Inserir no fim (C)
    inserirInicio(&lista, 1); // Inserir no início (B)
    inserirFim(&lista, 7); // Inserir no fim (C)

    printf("Lista inicial: ");
    imprimirLista(lista);

    // Excluir elementos da lista
    excluirInicio(&lista); // Excluir do início (D)
    printf("Depois de excluir do inicio: ");
    imprimirLista(lista);

    excluirFim(&lista); // Excluir do fim (E)
    printf("Depois de excluir do fim: ");
    imprimirLista(lista);

    // Procurar por elementos na lista
    printf("Procurando por 3 na lista: %d\n", procurarElemento(lista, 3)); // Procurar elemento (F)
    printf("Procurando por 1 na lista: %d\n", procurarElemento(lista, 1)); // Procurar elemento (F)

    // Ordenar a lista
    ordenarLista(&lista); // Ordenar a lista (G)
    printf("Depois de ordenar a lista: ");
    imprimirLista(lista);

    // Inserir elementos de forma ordenada
    inserirOrdenado(&lista, 4); // Inserir de forma ordenada (H)
    printf("Depois de inserir 4 de forma ordenada: ");
    imprimirLista(lista);

    // Excluir elemento do meio
    excluirMeio(&lista, 4); // Excluir do meio (G)
    printf("Depois de excluir 4 do meio da lista: ");
    imprimirLista(lista);

    // Inserir elemento no meio da lista com repetição
    inserirOrdenadoComRepeticao(&lista, 4); // Inserir de forma ordenada com repetição (H)
    inserirOrdenadoComRepeticao(&lista, 2); // Inserir de forma ordenada com repetição (H)
    printf("Depois de inserir 4 e 2 de forma ordenada com repeticao: ");
    imprimirLista(lista);

    return 0;
}