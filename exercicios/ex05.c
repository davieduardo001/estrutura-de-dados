#include<stdlib.h>
#include<stdio.h>

//funcao definida por g()

int g(int x) {
    if(x == 0) return -1;
    else return (g(x-1)+6);
}

int main() {

    printf("return: %d\n", g(12));

    return 0;
}