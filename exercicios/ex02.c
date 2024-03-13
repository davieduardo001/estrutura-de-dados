#include<stdio.h>

// recursividade 2

int g(int x) {
    if(x == 0) return -1;
    if(x > 0) return (4*g(x-1)+6);
}

int main() {

    printf("g(3) = %d\n", g(3));

    return 0;
}