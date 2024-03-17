#include<stdio.h>

int quantidadeDeDigitos(int inteiro) {

    int divisor = inteiro;
    int digitos = 0;

    while(divisor >= 0) {
        divisor = divisor % 10;
        digitos++;
    }

    return digitos;
}

int main() {

    int n = 23;
    printf("inteiro: %d resultado %d \n", n, quantidadeDeDigitos(n));
    return 0;
}