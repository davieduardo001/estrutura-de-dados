#include<stdio.h>
#include<stlib.h>

int main() {
    int inp = 2
    int out = f(inp);

    printf("dominio: %d => contra dominio: %d\n", inp, out);

    return 0;
}

int f(int dominio) {
    return dominio*dominio;
}