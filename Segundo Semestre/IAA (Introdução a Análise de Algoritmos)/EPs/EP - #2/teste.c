/**
 * @file ep.c
 * @brief Contém uma aplicação da estratégia de tentativa e erro (backtracking).
 * @author Gustavo Henrique Ferreira Alves NUSP 15674466
 */
#include "ep.h"

#define TRUE 1
#define FALSE 0
#define Boolean int

// vetor [1 .. G->M] de arestas com um valor "booleano" indicando se ja estao sendo usadas
// ao final do algoritmo, se houver uma solucao, esse vetor indicara as arestas que compoem essa solucao
int * arestaUsada;
// vetor auxiliar que salva o estado de menor caminho do grafo ao achar uma solucao
// usado para copiar o estado de arestaUsada em determinado momento, visto que 
// arestaUsada perde seu estado ao final do processo de calcular todos os caminhos possiveis
int * arestaUsadaMenorCaminho;
// vetor [1 .. G->N] de vertices com um valor que indica o grau desse vertice
// precisamente, indica a contagem do grau do vertice com um limitante superior de 2
// assim, garantimos que vertices de grau 2 foram visitados apenas uma vez durante o caminho
int * grauDoVertice;
int menorPeso = -1; // variavel para guardar o menor custo encontrado ao percorrer as possiveis solucoes

char * autor(void) {
	return "Gustavo Henrique Ferreira Alves ; 15674466";
}

// testar que todos os vertices foram alcancados nao garante solucao
// em um caminho hamiltoniano, cada vertice eh visitado apenas uma vez
// o que implica todos os vertices terem grau 2 (uma visita na ida, a outra na volta da recursao)
// caso atipico: se o grafo for composto por vários circuitos disjuntos que cobrem o grafo todo,
// os graus serão todos 2 e esta função indicara solucao, mesmo nao sendo 
// esta situação é evitada pela maneira como o circuito é construidoV
Boolean ehSolucao(struct grafo * G) { 
  #if DEBUG
	  for (int i = 0; i < G->N; i++) printf("%d ", grauDoVertice[i]);
    puts("");
    puts("---");
  # endif

	for (int i = 0; i < G->N; i++) {
    // grau < 2: vertice nao coberto
    // grau > 2: vertice visitado mais de uma vez
		if (grauDoVertice[i] != 2) return FALSE;
	}

	return TRUE;
}

Boolean ehAceitavel(struct grafo * G, int arestaATestar, int verticeAtual) {
	if (arestaUsada[arestaATestar]) return FALSE; // aresta a testar está em uso. Não é aceitável
 
  // visto que G->A eh uma "matriz achatada" [1 .. 3 * G->M]
  // acessamos cada "linha" da matriz na forma 3 * indice_coluna
  int orig = G->A[3 * arestaATestar];
  int dest = G->A[3 * arestaATestar + 1];

  // NOTA: o conceito de orig/dest nao existe em um grafo nao-direcional
  // ainda assim, a estrutura G->A possui essa representacao nao exata
  // para contornar isso, vamos testar os dois casos (ida e volta) para acomodar possiveis caminhos diferentes
  // tomados no percurso

  // arestaATestar conecta no vértice verticeAtual e
  // vértice no outro extremo da aresta (ainda) não foi coberto.
  if (orig == verticeAtual && grauDoVertice[dest] < 2) return TRUE;
  if (dest == verticeAtual && grauDoVertice[orig] < 2) return TRUE; 

	return FALSE;
}

// assume que a aresta eh aceitavel
// registra o movimento no vetor arestaUsada e acrescenta o grau dos vertices
// retorna o proximo vertice, ou seja, da outra extremidade da aresta analisada 
int aumentaCaminho(struct grafo * G, int arestaAcrescentar, int verticeAtual) {
  int orig = G->A[3 * arestaAcrescentar];
  int dest = G->A[3 * arestaAcrescentar + 1];

  #if DEBUG
    printf("%d -> %d\n", orig, dest);
  #endif

  arestaUsada[arestaAcrescentar] = TRUE;
	grauDoVertice[orig]++;
  grauDoVertice[dest]++;
	
  // ajusta o lado
  // EXPLICACAO: como mencionado, o conceito de orig/dest nao existe num grafo nao-direcional
  // o codigo abaixo contorna o problema de pegar o "proximo vertice", independente do sentido escolhido
  if (orig == verticeAtual)
    return dest;
  return orig;
}

void removeCaminho(struct grafo * G, int arestaRemover) {
  int orig = G->A[3 * arestaRemover];
  int dest = G->A[3 * arestaRemover + 1];

  arestaUsada[arestaRemover] = FALSE;
	grauDoVertice[orig]--;
  grauDoVertice[dest]--;
}

int getPeso(struct grafo * G, int aresta) {
  return G->A[3 * aresta + 2];
}

Boolean backtrack(struct grafo * G, int verticeAtual, int numArestasUsadas, int pesoAtual) {
  #if DEBUG 
    printf("verticeAtual: %d\n", verticeAtual);
  #endif
  
  if (G->N == numArestasUsadas && ehSolucao(G)) {
    menorPeso = (menorPeso == -1 || pesoAtual < menorPeso) ? pesoAtual : menorPeso;
    
    for (int i = 0; i < G->M; i++) {
      arestaUsadaMenorCaminho[i] = arestaUsada[i];
    }

    return TRUE;
  }

  int achouSolucao = FALSE;

  // a lista nao esta ordenada: sempre comecar do zero!
  for (int aresta = 0; aresta < G->M; aresta++) {
    if (ehAceitavel(G, aresta, verticeAtual)) {
      // registra movimento com aumentaCaminho e retorna o prox vertice a calcular
      int proxVertice = aumentaCaminho(G, aresta, verticeAtual);
      int proxPeso = pesoAtual + getPeso(G, aresta);

      if (menorPeso == -1 || proxPeso < menorPeso) {
        achouSolucao = backtrack(G, proxVertice, numArestasUsadas + 1, proxPeso) || achouSolucao;
      }

      removeCaminho(G, aresta);
    }
  }

  return achouSolucao;
}

int iniciaEexecuta(struct grafo * G, int verticeInicial) {
  grauDoVertice = calloc(G->N, sizeof(int));
  arestaUsada = calloc(G->M, sizeof(int));
  arestaUsadaMenorCaminho = calloc(G->M, sizeof(int));

  // como o circuito Hamiltoniano inclui todos os vértices do grafo, tanto faz por onde começa. 	
  int r = backtrack(G, verticeInicial, 0, 0);
	
  #if DEBUG 
    printf("menorPeso: %d\n", menorPeso);
  #endif

  if (r) puts("Achou solução");
  else puts("Não achou solução");
  
  // atribuimos arestaUsada a lista de flags de selecao de aresta do grafo para imprimir no mermaid (grafico visual)
  // isso eh usado para informar quais arestas serao destacadas
  for (int i = 0; i < G->M; i++) {
		G->S[i] = arestaUsadaMenorCaminho[i];

    #if DEBUG
      printf("%d ", G->A[i * 3 + 2]);
    #endif
	}

  #if DEBUG
    puts("");
  #endif

	return r;
}

void termina() {
  free(grauDoVertice);
	free(arestaUsada);
  free(arestaUsadaMenorCaminho);
}