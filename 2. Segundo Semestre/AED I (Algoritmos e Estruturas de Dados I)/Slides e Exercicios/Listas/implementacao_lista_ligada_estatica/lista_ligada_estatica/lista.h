#define FALSE 0
#define TRUE 1

typedef int Elemento;
typedef int Boolean;

typedef struct {

	Elemento valor;
	int proximo;

} No;

typedef struct {

	No * nos;
	int primeiro;
	int livre;
	int tamanho;
	int capacidade;

} ListaLigada;

ListaLigada * cria_lista(int n);
int tamanho();
void imprime(ListaLigada * lista);
int busca(ListaLigada * lista, Elemento e);
Boolean insere(ListaLigada * lista, Elemento e, int indice);
Boolean remove_elemento(ListaLigada * lista, Elemento e);
