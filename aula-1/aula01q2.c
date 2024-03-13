#include<stdio.h>
#include<stdlib.h>

#define ERR 1

// dominio/contra dominio

int main() {
    int inp = 2
    int out = f(inp);

    printf("dominio: %d => contra dominio: %d\n", inp, out);

    return 0;
}

int f(int dominio) {
    if(dominio == 2  || dominio == 3 || dominio == 4 || dominio == 5)
        return dominio*dominio;
    else {
        printf("err!\n");
        exit(ERR)
    }
}