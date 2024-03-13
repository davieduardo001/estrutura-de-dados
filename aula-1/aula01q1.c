#include<stdio.h>
#include<stdlib.h>

// dominio => contra dominio

char funcao1(int dominio) {
    char contraDominio;
    switch(dominio) {
        case 1:
            contraDominio = 'C';
            break;
        case 2:
            contraDominio = 'D';
            break;
        case 3:
            contraDominio = 'E';
            break;
        case 4:
            contraDominio = 'F';
            break;
        default:
            printf("err!\n");
            exit(1);
    }

    return contraDominio;
}

char f(int);

int main() {
    char ch = funcao1(54);

    printf("return: %c\n", ch);

    return 0;
}

char f(int x) {
    if(x == 1) return('C');
    else if (x == 2) return('D');
    else if (x == 3) return('E');
    else if (x == 4) return('B');
    else {
        printf("err!\n");
        exit(1);
    }
}