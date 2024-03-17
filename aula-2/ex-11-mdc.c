#include<stdio.h>
#include<stdlib.h>


int calcularMDC(int a, int b) {
//    int resto;
//
//    do {
//        resto = a % b;
//        a = b;
//        b = resto;
//    } while (b != 0);
//
//    return a;

    if(b==0) return a;
    else return(calcularMDC(b, a % b));
}

int main() {

    printf("resultado: %d\n", calcularMDC(24, 36));

    return 0;
}