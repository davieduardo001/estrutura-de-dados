#include<stdio.h>

// fatorial recursivo

int fat(int n) {

    if(n <= 1) {
        return 1;
    } else {
        return n * fat(n - 1);
    }

}

int main() {

    printf("fatorial de %d eh %d\n", 4, fat(4));

    return 0;
}