#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

ListaLigada * cria_lista(int n){

	int i;

	ListaLigada * lista = (ListaLigada *) malloc(sizeof(ListaLigada));

	lista->capacidade = n;
	lista->nos = (No *) malloc (lista->capacidade * sizeof(No));
	lista->tamanho = 0;
	lista->primeiro = -1;
	lista->livre  = 0;

	for(i = 0; i < lista->capacidade - 1; i++){

		lista->nos[i].proximo = i + 1;
	}

	lista->nos[i].proximo = -1;

	return lista;
}

int tamanho(ListaLigada * lista){

	return lista->tamanho;
}

void imprime(ListaLigada * lista){

	int i;

	printf("Lista:");

	for(i = lista->primeiro; i >= 0; i = lista->nos[i].proximo){

		printf(" %d", lista->nos[i].valor);
	}

	printf("\nNos livres:");

	for(i = lista->livre; i >= 0; i = lista->nos[i].proximo){

		printf(" %d", i);
	}

	printf("\n\n");
}

int busca(ListaLigada * lista, Elemento e){

	int i, j;

	for(i = lista->primeiro, j = 0; i >= 0; i = lista->nos[i].proximo, j++){

		if(lista->nos[i].valor == e) return j;
	}
	
	return -1;
}

Boolean insere(ListaLigada * lista, Elemento e, int indice){

	int i, j, novo;
	
	if(lista->livre >= 0 && lista->tamanho < lista->capacidade){

		novo = lista->livre;
		lista->livre = lista->nos[lista->livre].proximo;
	
		lista->nos[novo].valor = e;

		if(indice == 0){
		
			lista->nos[novo].proximo = lista->primeiro;
			lista->primeiro = novo;
		}
		else {

			for(i = lista->primeiro, j = 0; i >= 0; i = lista->nos[i].proximo, j++){

				if(j == indice - 1) break;
			}

			printf("J = %d\n", j);

			lista->nos[novo].proximo = lista->nos[i].proximo;
			lista->nos[i].proximo = novo;
		}

		lista->tamanho++;
		return TRUE;
	}

	return FALSE;
}

Boolean remove_elemento(ListaLigada * lista, Elemento e){

	return FALSE;
}

int main(){


	ListaLigada * lista = cria_lista(10);
	imprime(lista);

	insere(lista, 10, 0); 	imprime(lista);
	insere(lista, 20, 1); 	imprime(lista);
	insere(lista, 30, 0); 	imprime(lista);
	insere(lista, 40, 1); 	imprime(lista);
	insere(lista, 50, 2); 	imprime(lista);

	return 0;
}
