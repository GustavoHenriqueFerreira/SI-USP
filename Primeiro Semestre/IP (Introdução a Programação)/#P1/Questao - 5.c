#include <stdio.h>

void calcularMediaNotas(int notas[]) {
    int indiceMenor = 0, indiceMaior = 0;
    float soma = 0.0, media;

    for (int i = 1; i < 6; i++) {
        if (notas[i] < notas[indiceMenor]) {
            indiceMenor = i;
        }
        if (notas[i] > notas[indiceMaior]) {
            indiceMaior = i;
        }
    }

    for (int i = 0; i < 6; i++) {
        if (i != indiceMenor && i != indiceMaior) {
            soma += notas[i];
        }
    }

    media = soma / 4.0;

    printf("A media das notas apos descartar a maior e a menor: %.2f\n", media);
}

int main() {
    int notas[6];

    printf("Digite as notas dos juizes (entre 0 e 10):\n");
    for (int i = 0; i < 6; i++) {
        printf("Nota do juiz %d: ", i + 1);
        scanf("%d", &notas[i]);
    }

    calcularMediaNotas(notas);

    return 0;
}