#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void insercaoValoresTamanhoVetor(int tamanho, int vetor[])
{
    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    int maior = vetor[0], menor = vetor[0], soma = vetor[0];
    int posicaoMaior = 0, posicaoMenor = 0;

    for (int i = 1; i < tamanho; i++)
    {
        if (maior < vetor[i])
        {
            maior = vetor[i];
            posicaoMaior = i;
        }

        if (menor > vetor[i])
        {
            menor = vetor[i];
            posicaoMenor = i;
        }

        soma = soma + vetor[i];
    }

    printf("Maior valor: %d\n", maior);
    printf("Posicao maior valor: %d\n", posicaoMaior + 1);
    printf("Menor valor: %d\n", menor);
    printf("Posicao menor valor: %d\n", posicaoMenor + 1);
    printf("Soma de valores: %d\n", soma);
    printf("Media de valores: %.2f\n", (float)soma / 4);
}

void encontrarRepeticoes(int x, int tamanho, int vetor[])
{
    int numeroRepeticoes = 0;
    for (int i = 0; i < tamanho; i++)
    {
        if (x == vetor[i])
        {
            numeroRepeticoes++;
            printf("Repeticao na posicao: %d\n", i + 1);
        }
    }

    printf("Numero de repeticoes: %d\n", numeroRepeticoes);
}

int main(int argc, char const *argv[])
{
    int tamanhoVetor = 4;
    int vetor[tamanhoVetor];

    /* Parte - a e b */
    insercaoValoresTamanhoVetor(tamanhoVetor, vetor);

    /* Parte c */
    int x;
    printf("Digite o valor que quer encontrar se ha repeticao:\n");
    scanf("%d", &x);

    encontrarRepeticoes(x, tamanhoVetor, vetor);
    return 0;
}