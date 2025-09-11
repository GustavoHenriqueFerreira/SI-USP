#include <stdio.h>

float celsiusParaFahrenheit(float celsius) {
    return celsius * 9.0 / 5.0 + 32;
}

int main() {
    float celsius, fahrenheit;

    printf("Digite a temperatura em graus Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = celsiusParaFahrenheit(celsius);

    printf("%.2f graus Celsius e igual a %.2f graus Fahrenheit.\n", celsius, fahrenheit);

    return 0;
}