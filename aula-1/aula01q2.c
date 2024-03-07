#include<stdio.h>
#include<stlib.h>

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
        exit(1)
    }
}