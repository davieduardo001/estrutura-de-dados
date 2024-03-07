#include<stdio.h>

//int f(int n) {
//    int count = n;
//    int fat = n;
//
//    if (n > 0) {
//        count--;
//        while(count != 0) {
//            fat *= count;
//            count--;
//        }
//        return fat;
//    }
//}

int fatorial(int n) {
    int resp = 1;
    for(int i = 1; i <= n; i++) {
        resp = resp * i;
    }

    return resp;
}

int main() {
    int n;

    printf("digite um inteiro positivo: ");
    scanf("%d", &n);

    printf("%d", fatorial(n));
    return 0;
}