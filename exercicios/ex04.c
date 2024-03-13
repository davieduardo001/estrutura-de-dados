#include<stdio.h>
#include<stdlib.h>

int fibonacci(int n) {
    if(n == 1 || n == 2) return 1;
    else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {

    printf("sequencia de fibonacci da posicao %d: %d\n", 25, fibonacci(25));

    return 0;
}