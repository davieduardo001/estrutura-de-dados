//Escreva uma função recursiva para determinar o 34° termo de uma Progressão Geométrica de
// primeiro termo 4 e razão 1.25. Utilize essa função para calcular a soma dos 34 termos dessa PG

#include <stdio.h>
#include <math.h>

// Função para calcular o n-ésimo termo de uma PG
double calcularTermo(int n) {
    double primeiroTermo = 4.0; // Primeiro termo
    double razao = 1.25; // Razão
    double termo = primeiroTermo * pow(razao, n - 1);
    return termo;
}

// Função para calcular a soma dos n termos de uma PG
double calcularSoma(int n) {
    double primeiroTermo = 4.0; // Primeiro termo
    double razao = 1.25; // Razão
    double soma = primeiroTermo * (pow(razao, n) - 1) / (razao - 1);
    return soma;
}

int main() {
    int n = 34; // Número de termos
    double termo34 = calcularTermo(n);
    double soma34 = calcularSoma(n);

    printf("34º termo: %.2lf\n", termo34);
    printf("Soma dos 34 termos: %.2lf\n", soma34);

    return 0;
}
