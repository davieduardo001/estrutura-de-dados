#include<stdio.h>
#include<stlib.h>

//char funcao1(int dominio) {
//    char contraDominio;
//    switch(dominio) {
//        case 1:
//            contraDominio = 'C';
//            break;
//        case 2:
//            contraDominio = '';
//            break;
//        default:
//            print('err');
//    }
//
//    return contraDominio;
//}

char f(int);

int main() {
    char ch = f(3);

    printf("return: %c", ch);

    return 0;
}

char f(int x) {
    if(x == 1) return('C');
    else if (X == 2) return('D');
    else if (X == 3) return('E');
    else if (X == 4) return('B');
    else {
        printf("err!");
        exit(1);
    }
}