#include<stdlib.h>
#include<stdio.h>

//Escreva uma função que recebe por parâmetro um valor inteiro e positivo N para determinar o
//valor da soma dos N primeiros termos da série harmônica, definida por:
    // S = 1 + 1/2 + 1/3 + 1/4 + ... + 1/N
//Curiosidade:
//A série harmônica diverge, o que significa que a soma dos termos tende ao infinito à medida que
//mais termos são adicionados.

double serieArmonica(int n) {
    if(n == 1) return (double)1;
    else return ((double)1 / n + serieArmonica(n-1));
}

int main() {

    int n = 5;

    printf("serie de %i eh %.6f\n", n, serieArmonica(n));

    return 0;
}