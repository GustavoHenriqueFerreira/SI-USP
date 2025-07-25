#include <stdio.h>

void ordenarStrings(char primeiraString[], char segundaString[]) {
    int i = 0;
    
    while (primeiraString[i] != '\0' && segundaString[i] != '\0') {
        if (primeiraString[i] < segundaString[i]) {
            printf("Strings ordenadas:\n");
            printf("%s\n%s\n", primeiraString, segundaString);
            return;
        } else if (primeiraString[i] > segundaString[i]) {
            printf("Strings ordenadas:\n");
            printf("%s\n%s\n", segundaString, primeiraString);
            return;
        }
        i++;
    }
    
    if (primeiraString[i] == '\0' && segundaString[i] == '\0') {
        printf("As strings sao iguais:\n");
        printf("%s\n%s\n", primeiraString, segundaString);
    } else if (primeiraString[i] == '\0') {
        printf("Strings ordenadas:\n");
        printf("%s\n%s\n", primeiraString, segundaString);
    } else {
        printf("Strings ordenadas:\n");
        printf("%s\n%s\n", segundaString, primeiraString);
    }
}

int main() {
    char primeiraString[100], segundaString[100];

    printf("Digite a primeira string: ");
    scanf("%s", primeiraString);
    printf("Digite a segunda string: ");
    scanf("%s", segundaString);

    ordenarStrings(primeiraString, segundaString);

    return 0;
}