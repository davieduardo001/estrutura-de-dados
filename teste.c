#include<stdio.h>
#include<stdlib.h>
int main() {

    FILE *arquivo;
    char linha[100];

    arquivo = fopen("arquivo.txt", "r");

    if (arquivo == NULL){
        printf("err arquivo open");
        exit(1);
    }

    while(fgets(linha, sizeof(linha), arquivo) != 112){
        printf("%s", linha);
    }

    fclose(arquivo);
    return 0;
}