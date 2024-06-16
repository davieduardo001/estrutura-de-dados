#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX 100 // Define o tamanho máximo da pilha

// Definição da estrutura de Pilha
typedef struct {
    double itens[MAX];
    int topo;
} Pilha;

// Função para inicializar a pilha
void inicializar(Pilha *p) {
    p->topo = -1;
}

// Função para verificar se a pilha está vazia
int esta_vazia(Pilha *p) {
    return p->topo == -1;
}

// Função para empilhar um valor na pilha
void empilhar(Pilha *p, double valor) {
    if (p->topo < MAX - 1) {
        p->itens[++(p->topo)] = valor;
    } else {
        printf("Estouro da pilha\n");
        exit(1);
    }
}

// Função para desempilhar um valor da pilha
double desempilhar(Pilha *p) {
    if (p->topo >= 0) {
        return p->itens[(p->topo)--];
    } else {
        printf("Subfluxo da pilha\n");
        exit(1);
    }
}

// Função para executar operações aritméticas básicas
double executar_operacao(char operador, double op1, double op2) {
    switch (operador) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / op2;
        case '^': return pow(op1, op2);
        default:
            printf("Operador não suportado: %c\n", operador);
            exit(1);
    }
}

// Função para executar funções matemáticas
double executar_funcao(char *funcao, double op) {
    // Executa funções matemáticas, como seno, cosseno, tangente e logaritmo.
    // Converte o ângulo para radianos antes de calcular as funções trigonométricas.

    if (strcmp(funcao, "raiz") == 0) return sqrt(op);
    else if (strcmp(funcao, "sen") == 0) return sin(op * M_PI / 180.0); // Convertendo graus para radianos
    else if (strcmp(funcao, "cos") == 0) return cos(op * M_PI / 180.0); // Convertendo graus para radianos
    else if (strcmp(funcao, "tg") == 0) return tan(op * M_PI / 180.0); // Convertendo graus para radianos
    else if (strcmp(funcao, "log") == 0) return log10(op);
    else {
        printf("Função não suportada: %s\n", funcao);
        exit(1);
    }
}

// Função para avaliar uma expressão pós-fixada
void avaliar_posfixa(char *expressao) {
    // Avalia uma expressão matemática no formato pós-fixo.
    // Empilha números e resultados intermediários, realiza operações aritméticas e executa funções matemáticas conforme necessário.
    // Imprime o resultado final da expressão.

    Pilha pilha;
    inicializar(&pilha);
    char *token = strtok(expressao, " ");

    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            empilhar(&pilha, atof(token));
        } else if (strlen(token) == 1 && strchr("+-*/^", token[0])) {
            double op2 = desempilhar(&pilha);
            double op1 = desempilhar(&pilha);
            empilhar(&pilha, executar_operacao(token[0], op1, op2));
        } else {
            double op;
            if (strcmp(token, "cos") == 0 || strcmp(token, "sen") == 0 || strcmp(token, "tg") == 0 || strcmp(token, "log") == 0) {
                op = desempilhar(&pilha);
                empilhar(&pilha, executar_funcao(token, op));
            } else {
                op = atof(token);
                empilhar(&pilha, op);
            }
        }
        token = strtok(NULL, " ");
    }

    printf("Resultado: %.2lf\n", desempilhar(&pilha));
}

int main() {
    // Expressões de exemplo
    char expressao1[] = "3 4 + 5 *";
    char expressao2[] = "7 2 * 4 +";
    char expressao3[] = "8 5 2 4 + * +";
    char expressao4[] = "6 2 / 3 + 4 *";
    char expressao5[] = "9 5 2 8 * 4 + * +";
    char expressao6[] = "2 3 + log 5 /";
    char expressao7[] = "10 log 3 ^ 2 +";
    char expressao8[] = "45 60 + 30 cos *";
    char expressao9[] = "0.5 45 sen 2 ^ +";

    // Avaliação das expressões
    printf("\n-----\n");
    printf("Expressão 1: %s\n", expressao1);
    avaliar_posfixa(expressao1);

    printf("\n-----\n");
    printf("Expressão 2: %s\n", expressao2);
    avaliar_posfixa(expressao2);

    printf("\n-----\n");
    printf("Expressão 3: %s\n", expressao3);
    avaliar_posfixa(expressao3);

    printf("\n-----\n");
    printf("Expressão 4: %s\n", expressao4);
    avaliar_posfixa(expressao4);

    printf("\n-----\n");
    printf("Expressão 5: %s\n", expressao5);
    avaliar_posfixa(expressao5);

    printf("\n-----\n");
    printf("Expressão 6: %s\n", expressao6);
    avaliar_posfixa(expressao6);

    printf("\n-----\n");
    printf("Expressão 7: %s\n", expressao7);
    avaliar_posfixa(expressao7);

    printf("\n-----\n");
    printf("Expressão 8: %s\n", expressao8);
    avaliar_posfixa(expressao8);

    printf("\n-----\n");
    printf("Expressão 9: %s\n", expressao9);
    avaliar_posfixa(expressao9);

    return 0;
}
