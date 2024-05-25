#include <stdio.h>
#include <stdlib.h>

// Função para inserir valores no vetor até o tamanho máximo especificado
int insercaoValoresTamanhoVetor(int tamanhoMaximo, int vetor[])
{
  int tamanhoVetor = 0; // Contador para o tamanho real do vetor
  printf("Digite os elementos do vetor:\n");
  for (int i = 0; i < tamanhoMaximo; i++)
  {
    printf("Elemento %d: ", i + 1);
    int temp;
    scanf("%d", &temp); // Armazena o valor digitado temporariamente

    // Verifica se o elemento é duplicado
    int duplicado = 0;
    for (int j = 0; j < i; j++)
    {
      if (temp == vetor[j])
      {
        duplicado = 1;
        break;
      }
    }

    // Se o elemento é duplicado, pede um novo valor
    if (duplicado)
    {
      printf("Por favor digite um numero diferente dos usados\n");
      i--;      // Decrementa i para tentar novamente essa posição
      continue; // Salta para a próxima iteração do loop, assim não tem problemas de inserção de valores
    }

    // Se o número é negativo, para a inserção
    if (temp < 0)
    {
      printf("Insercao parada devido ao numero ser negativo\n");
      break;
    }

    // Adiciona o elemento ao vetor e incrementa o tamanho
    vetor[i] = temp;
    tamanhoVetor++;

    // Se alcançou o tamanho máximo do vetor, para a inserção
    if (i == tamanhoMaximo - 1)
    {
      printf("Insercao parada devido ao tamanho do vetor\n");
      break;
    }
  }

  return tamanhoVetor; // Retorna o tamanho real do vetor
}

// Função para ordenar o vetor usando Bubble Sort
void ordernarVetor(int tamanho, int *vetor)
{
  // Itera sobre todos os elementos do vetor
  for (int i = 0; i < tamanho - 1; i++)
  {
    // Para cada elemento, compara-o com os elementos subsequentes
    for (int j = 0; j < tamanho - i - 1; j++)
    {
      // Se o elemento atual é maior que o próximo elemento
      if (vetor[j] > vetor[j + 1])
      {
        // Troca os elementos de posição
        int temp = vetor[j];
        vetor[j] = vetor[j + 1];
        vetor[j + 1] = temp;
      }
    }
  }
}

// Função para mesclar dois vetores ordenados em um terceiro vetor sem duplicatas
void mergeVetores(int *vetor1, int tamanho1, int *vetor2, int tamanho2, int *vetorResultado, int *tamanhoResultado)
{
  int i = 0, j = 0, k = 0; // Índices para vetor1, vetor2 e vetorResultado

  // Mescla os vetores enquanto há elementos em ambos
  while (i < tamanho1 && j < tamanho2)
  {
    if (vetor1[i] < vetor2[j])
    {
      // Adiciona o elemento de vetor1 se não for duplicado
      if (k == 0 || vetorResultado[k - 1] != vetor1[i])
      {
        vetorResultado[k++] = vetor1[i];
      }
      i++;
    }
    else if (vetor2[j] < vetor1[i])
    {
      // Adiciona o elemento de vetor2 se não for duplicado
      if (k == 0 || vetorResultado[k - 1] != vetor2[j])
      {
        vetorResultado[k++] = vetor2[j];
      }
      j++;
    }
    else
    {
      // Adiciona o elemento comum uma vez só
      if (k == 0 || vetorResultado[k - 1] != vetor1[i])
      {
        vetorResultado[k++] = vetor1[i];
      }
      i++;
      j++;
    }
  }

  // Adiciona os elementos restantes de vetor1
  while (i < tamanho1)
  {
    if (k == 0 || vetorResultado[k - 1] != vetor1[i])
    {
      vetorResultado[k++] = vetor1[i];
    }
    i++;
  }

  // Adiciona os elementos restantes de vetor2
  while (j < tamanho2)
  {
    if (k == 0 || vetorResultado[k - 1] != vetor2[j])
    {
      vetorResultado[k++] = vetor2[j];
    }
    j++;
  }

  *tamanhoResultado = k; // Define o tamanho do vetor resultado
}

// Função para encontrar elementos repetidos entre dois vetores
void encontrarRepeticoes(int *vetor1, int tamanho1, int *vetor2, int tamanho2, int *vetorResultado, int *tamanhoResultado)
{
  int k = 0; // Índice para vetorResultado

  // Itera sobre todos os elementos de vetor1
  for (int i = 0; i < tamanho1; i++)
  {
    // Para cada elemento de vetor1, verifica se está em vetor2
    for (int j = 0; j < tamanho2; j++)
    {
      if (vetor1[i] == vetor2[j])
      {
        // Verifica se o elemento já está no vetorResultado
        int repetido = 0;
        for (int l = 0; l < k; l++)
        {
          if (vetor1[i] == vetorResultado[l])
          {
            repetido = 1;
            break;
          }
        }

        // Se não está repetido, adiciona ao vetorResultado
        if (!repetido)
        {
          vetorResultado[k++] = vetor1[i];
        }
      }
    }
  }

  *tamanhoResultado = k; // Define o tamanho do vetor resultado
}

// Função para listar os elementos de um vetor
void listarVetor(int *vetor, int tamanho)
{
  for (int i = 0; i < tamanho; i++)
  {
    printf("%d ", vetor[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[])
{
  int tamanhoMaximoPrimeiros = 20; // Tamanho máximo dos primeiros vetores
  int primeiroVetor[tamanhoMaximoPrimeiros];
  int segundoVetor[tamanhoMaximoPrimeiros];

  /* Parte - a */
  // Inserção de valores nos vetores
  int tamanhoPrimeiroVetor = insercaoValoresTamanhoVetor(tamanhoMaximoPrimeiros, primeiroVetor);
  int tamanhoSegundoVetor = insercaoValoresTamanhoVetor(tamanhoMaximoPrimeiros, segundoVetor);

  /* Parte - d */
  // Exibe os vetores sem ordem
  printf("Sem Ordem - Primeiro Vetor: ");
  listarVetor(primeiroVetor, tamanhoPrimeiroVetor);

  /* Parte - d */
  printf("Sem Ordem - Segundo Vetor: ");
  listarVetor(segundoVetor, tamanhoSegundoVetor);

  /* Parte - b */
  // Ordena os vetores
  ordernarVetor(tamanhoPrimeiroVetor, primeiroVetor);
  /* Parte - d */
  printf("Ordenado - Primeiro Vetor: ");
  listarVetor(primeiroVetor, tamanhoPrimeiroVetor);

  /* Parte - b */
  ordernarVetor(tamanhoSegundoVetor, segundoVetor);
  /* Parte - d */
  printf("Ordenado - Segundo Vetor: ");
  listarVetor(segundoVetor, tamanhoSegundoVetor);

  /* Parte - c.1 */
  // Tamanho máximo do vetor resultante da mesclagem
  int tamanhoMaximoUltimos = 40;
  int terceiroVetor[tamanhoMaximoUltimos];
  int tamanhoRealTerceiroVetor = 0;

  /* Parte - d */
  // Mescla os dois vetores ordenados
  mergeVetores(primeiroVetor, tamanhoPrimeiroVetor, segundoVetor, tamanhoSegundoVetor, terceiroVetor, &tamanhoRealTerceiroVetor);
  printf("Merge (Primeiro e o Segundo vetor) - Terceiro Vetor: ");
  listarVetor(terceiroVetor, tamanhoRealTerceiroVetor);

  /* Parte - c.2 */
  // Encontra os elementos repetidos entre os dois vetores
  int quartoVetor[tamanhoMaximoUltimos];
  int tamanhoRealQuartoVetor = 0;
  encontrarRepeticoes(primeiroVetor, tamanhoPrimeiroVetor, segundoVetor, tamanhoSegundoVetor, quartoVetor, &tamanhoRealQuartoVetor);

  /* Parte - d */
  /* Parte - e */
  printf("Repetiram duas vezes (Primeiro e o Segundo vetor) - Quarto Vetor: ");
  listarVetor(quartoVetor, tamanhoRealQuartoVetor);

  return 0;
}