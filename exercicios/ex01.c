#include<stdio.h>
#include<stdlib.h>

int f(int x) {
    if(x == 0) return 3;
    else if(x > 0) return (2*f(x-1)+5);
}

int main() {

    printf("Resultado f(4): %d\n", f(4));

    return 0;
}