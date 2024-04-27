#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void imprimirPrimos(short int quantidadeNumeros)
{
  short int numeroInserido;
  short int arrayNumerosPrimos[quantidadeNumeros];

  for (int i = 0; i < quantidadeNumeros; i++)
  {
    printf("Que numero voce deseja inserir (apenas inteiros e positivos): ");
    scanf("%hd", &numeroInserido);

    while (numeroInserido <= 0)
    {
      printf("Por favor digite um numero inteiro e positivo: ");
      scanf("%hd", &numeroInserido);
    }

    short int naoEncontrouPrimo = 0;

    for (int j = 2; j * j <= numeroInserido; j++)
    {
      if (numeroInserido % j == 0)
      {
        naoEncontrouPrimo = 1;
        break;
      }
    }

    if ((naoEncontrouPrimo && numeroInserido > 1) || numeroInserido == 1)
    {
      arrayNumerosPrimos[i] = 0;
    }
    else
    {
      arrayNumerosPrimos[i] = numeroInserido;
    }
  }

  int numerosPrimosEncontrados = 0;
  printf("Numeros primos inseridos: \n");

  for (int i = 0; i < quantidadeNumeros; i++)
  {
    if (arrayNumerosPrimos[i] != 0)
    {
      printf("%hd; ", arrayNumerosPrimos[i]);
      numerosPrimosEncontrados++;
    }
  }

  if (numerosPrimosEncontrados == 0)
  {
    printf("Nao encontrou numeros primos\n");
  }

  printf("\n");
}

int main(int argc, char const *argv[])
{
  short int quantidadeNumerosInseridos;

  printf("Quantos numeros voce deseja inserir: ");
  scanf("%hd", &quantidadeNumerosInseridos);

  imprimirPrimos(quantidadeNumerosInseridos);

  return 0;
}