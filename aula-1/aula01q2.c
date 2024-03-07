#include<stdio.h>
#include<stlib.h>

int main() {
    int out = f(2);

    printf("resp: %d", out);

    return 0;
}

int f(int dominio) {
    return dominio*dominio;
}