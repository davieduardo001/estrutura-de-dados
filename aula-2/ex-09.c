#include<stdio.h>
#include<stdlib.h>

char f(int faixaDePontos) {

    char conceito;

    if(faixaDePontos >= 90 && faixaDePontos <= 100) conceito = 'A';
    else if(faixaDePontos >= 80 && faixaDePontos <= 89) conceito = 'B';
    else if(faixaDePontos >= 70 && faixaDePontos <= 79) conceito = 'C';
    else if(faixaDePontos >= 60 && faixaDePontos <= 69) conceito = 'D';
    else if(faixaDePontos >= 40 && faixaDePontos <= 59) conceito = 'E';
    else if(faixaDePontos < 40) conceito = 'F';

    return conceito;
}

int main() {

    int n = 40;

    printf("Conceito de %d eh %c\n", n, f(n));

    return 0;
}