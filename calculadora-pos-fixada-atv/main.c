#include "calculadora.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    ExpressaoResultado expressoes[MAX_EXPR]; // Array para armazenar as expressões e resultados

    // Definições das expressões de exemplo
    char expressao1[] = "3 4 + 5 *";
    char expressao2[] = "7 2 * 4 +";
    char expressao3[] = "8 5 2 4 + * +";
    char expressao4[] = "6 2 / 3 + 4 *";
    char expressao5[] = "9 5 2 8 * 4 + * +";
    char expressao6[] = "2 3 + log 5 /";
    char expressao7[] = "10 log 3 ^ 2 +";
    char expressao8[] = "45 60 + 30 cos *";
    char expressao9[] = "0.5 45 sen 2 ^ +";

    // Armazenamento das expressões e resultados
    strcpy(expressoes[0].expressao, expressao1);
    expressoes[0].resultado = avaliar_posfixa(expressao1);

    strcpy(expressoes[1].expressao, expressao2);
    expressoes[1].resultado = avaliar_posfixa(expressao2);

    strcpy(expressoes[2].expressao, expressao3);
    expressoes[2].resultado = avaliar_posfixa(expressao3);

    strcpy(expressoes[3].expressao, expressao4);
    expressoes[3].resultado = avaliar_posfixa(expressao4);

    strcpy(expressoes[4].expressao, expressao5);
    expressoes[4].resultado = avaliar_posfixa(expressao5);

    strcpy(expressoes[5].expressao, expressao6);
    expressoes[5].resultado = avaliar_posfixa(expressao6);

    strcpy(expressoes[6].expressao, expressao7);
    expressoes[6].resultado = avaliar_posfixa(expressao7);

    strcpy(expressoes[7].expressao, expressao8);
    expressoes[7].resultado = avaliar_posfixa(expressao8);

    strcpy(expressoes[8].expressao, expressao9);
    expressoes[8].resultado = avaliar_posfixa(expressao9);

    srand(time(NULL)); // Semente para gerar números aleatórios

    // Impressão das expressões e resultados com cores diferentes
    for (int i = 0; i < MAX_EXPR; i++) {
        int indice_cor = rand() % 6; // Gera um número aleatório entre 0 e 5 (6 cores diferentes)
        printf("-----\n");
        printf("Expressão %d: %s\n", i + 1, expressoes[i].expressao);
        imprimir_resultado_colorido(expressoes[i].expressao, expressoes[i].resultado, indice_cor);
    }

    return 0;
}
