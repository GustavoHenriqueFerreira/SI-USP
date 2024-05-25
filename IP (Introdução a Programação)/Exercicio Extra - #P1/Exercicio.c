#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool verificarBissexto(int ano) {
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        return true;
    } else {
        return false;
    }
}

bool dataValida(int dia, int mes, int ano) {
    int diasNoMes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (mes < 1 || mes > 12) {
        return false;
    }

    if (mes == 2 && verificarBissexto(ano)) {
        diasNoMes[1] = 29;
    }

    if (dia < 1 || dia > diasNoMes[mes - 1]) {
        return false;
    }

    return true;
}

int main(int argc, char *argv[]) {
    char data[11];
    int dia, mes, ano;

    printf("Digite uma data (DD/MM/AAAA): ");
    fgets(data, sizeof(data), stdin);

    if (sscanf(data, "%d/%d/%d", &dia, &mes, &ano) != 3) {
        printf("Formato de data inválido.\n");
        return 1;
    }

    if (dataValida(dia, mes, ano)) {
        printf("A data %02d/%02d/%04d: valida\n", dia, mes, ano);
    } else {
        printf("A data %02d/%02d/%04d: invalida\n", dia, mes, ano);
    }

    return 0;
}