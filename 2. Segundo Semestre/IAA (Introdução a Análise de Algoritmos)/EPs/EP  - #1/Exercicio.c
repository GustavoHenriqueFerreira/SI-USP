#include <stdio.h>
#include <stdlib.h>

int indiceMensagem = 0;

void indent(int n) {
    for (int i = 0; i < n; i++) {
        putchar('\t'); 
    }
}

void hanoi(int n, char origem, char destino, char auxiliar, int nivel) {
    indent(nivel);
    printf("%02d - Entrou no calculo de hanoi(%d, %c, %c, %c)\n", ++indiceMensagem, n, origem, destino, auxiliar);

    if (n == 1) {
        return;
    }

    hanoi(n - 1, origem, auxiliar, destino, nivel + 1);
    indent(nivel);
    printf("%02d - Retornou ao calculo de hanoi(%d, %c, %c, %c)\n", ++indiceMensagem, n, origem, destino, auxiliar);

    hanoi(1, origem, destino, auxiliar, nivel + 1); 
    indent(nivel);
    printf("%02d - Retornou ao calculo de hanoi(%d, %c, %c, %c)\n", ++indiceMensagem, n, origem, destino, auxiliar);

    hanoi(n - 1, auxiliar, destino, origem, nivel + 1);
    indent(nivel);
    printf("%02d - Retornou ao calculo de hanoi(%d, %c, %c, %c)\n", ++indiceMensagem, n, origem, destino, auxiliar);
}

int main(void) {
    hanoi(4, 'A', 'C', 'B', 0); 
    return 0;
}