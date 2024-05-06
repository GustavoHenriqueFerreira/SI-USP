#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int insercaoValoresTamanhoVetor(int tamanhoMaximo, int vetor[])
{
  int tamanhoVetor;
  printf("Digite os elementos do vetor:\n");
  for (int i = 0; i < tamanhoMaximo; i++)
  {
    tamanhoVetor = i;
    printf("Elemento %d: ", i + 1);
    int temp;
    scanf("%d", &temp);

    for (int j = 0; j < i; j++)
    {
      if (temp == vetor[j])
      {
        printf("Por favor digite um numero diferente dos usados\n");
        printf("Elemento %d: ", i + 1);
        scanf("%d", &temp);
        j = 0; // Reiniciando j para verificar novamente desde o início
      }
    }

    if (temp < 0 || i == tamanhoMaximo - 1)
    {
      printf("Insercao parada devido ao tamanho do vetor ou pelo numero ser negativo\n");
      break;
    }

    vetor[i] = temp;
  }

  return tamanhoVetor;
}

void ordernarVetor(int tamanho, int *vetor)
{
  for (int i = 0; i < tamanho; i++)
  {
    for (int j = 0; j < tamanho - i; j++)
    {
      if (vetor[j] > vetor[j + 1])
      {
        int temp = vetor[j];
        vetor[j] = vetor[j + 1];
        vetor[j + 1] = temp;
      }
    }
  }
}

void mergeVetores(int *vetor1, int tamanho1, int *vetor2, int tamanho2, int *vetorResultado, int *tamanhoResultado)
{
  int i = 0, j = 0, k = 0;

  while (i < tamanho1 && j < tamanho2)
  {
    if (vetor1[i] < vetor2[j])
    {
      if (k == 0 || vetorResultado[k - 1] != vetor1[i])
      {
        vetorResultado[k++] = vetor1[i];
      }
      i++;
    }
    else if (vetor2[j] < vetor1[i])
    {
      if (k == 0 || vetorResultado[k - 1] != vetor2[j])
      {
        vetorResultado[k++] = vetor2[j];
      }
      j++;
    }
    else // Se os elementos forem iguais
    {
      if (k == 0 || vetorResultado[k - 1] != vetor1[i])
      {
        vetorResultado[k++] = vetor1[i];
      }
      i++;
      j++;
    }
  }

  while (i < tamanho1)
  {
    if (k == 0 || vetorResultado[k - 1] != vetor1[i])
    {
      vetorResultado[k++] = vetor1[i];
    }
    i++;
  }

  while (j < tamanho2)
  {
    if (k == 0 || vetorResultado[k - 1] != vetor2[j])
    {
      vetorResultado[k++] = vetor2[j];
    }
    j++;
  }

  *tamanhoResultado = k;
}

void encontrarRepeticoes(int *vetor1, int tamanho1, int *vetor2, int tamanho2, int *vetorResultado, int *tamanhoResultado)
{
  int k = 0;

  for (int i = 0; i < tamanho1; i++)
  {
    for (int j = 0; j < tamanho2; j++)
    {
      if (vetor1[i] == vetor2[j])
      {
        // Verifica se o elemento já foi inserido no vetor resultado
        int repetido = 0;
        for (int l = 0; l < k; l++)
        {
          if (vetor1[i] == vetorResultado[l])
          {
            repetido = 1;
            break;
          }
        }

        // Se não foi repetido, insere no vetor resultado
        if (!repetido)
        {
          vetorResultado[k++] = vetor1[i];
        }
      }
    }
  }

  *tamanhoResultado = k;
}

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
  int tamanhoMaximoPrimeiros = 20;
  int primeiroVetor[tamanhoMaximoPrimeiros];
  int segundoVetor[tamanhoMaximoPrimeiros];

  /* Parte - a */
  int tamanhoPrimeiroVetor = insercaoValoresTamanhoVetor(tamanhoMaximoPrimeiros, primeiroVetor);
  int tamanhoSegundoVetor = insercaoValoresTamanhoVetor(tamanhoMaximoPrimeiros, segundoVetor);
  /* Parte - d */
  printf("Sem Ordem - Primeiro Vetor: ");
  listarVetor(primeiroVetor, tamanhoPrimeiroVetor);

  /* Parte - d */
  printf("Sem Ordem - Segundo Vetor: ");
  listarVetor(segundoVetor, tamanhoSegundoVetor);

  /* Parte - b */
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
  int tamanhoMaximoUltimos = 40;
  int terceiroVetor[tamanhoMaximoUltimos];
  int tamanhoRealTerceiroVetor = 0; // Variável para armazenar o tamanho real do vetor mesclado

  mergeVetores(primeiroVetor, tamanhoPrimeiroVetor, segundoVetor, tamanhoSegundoVetor, terceiroVetor, &tamanhoRealTerceiroVetor);

  /* Parte - d */
  printf("Merge (Primeiro e o Segundo vetor) - Terceiro Vetor: ");
  listarVetor(terceiroVetor, tamanhoRealTerceiroVetor);

  /* Parte - c.2 */
  int quartoVetor[tamanhoMaximoUltimos];
  int tamanhoRealQuartoVetor = 0;
  encontrarRepeticoes(primeiroVetor, tamanhoPrimeiroVetor, segundoVetor, tamanhoSegundoVetor, quartoVetor, &tamanhoRealQuartoVetor);

  /* Parte - d */
  /* Parte - e */
  printf("Repetiram duas vezes (Primeiro e o Segundo vetor) - Quarto Vetor: ");
  listarVetor(quartoVetor, tamanhoRealQuartoVetor);

  return 0;
}