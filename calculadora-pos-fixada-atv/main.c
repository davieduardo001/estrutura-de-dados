#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h> // Para gerar sementes para a função rand()

#define MAX 100 // Define o tamanho máximo da pilha

// Cores ANSI para formatação no terminal
#define ANSI_COLOR_RESET "\033[0m"
#define ANSI_COLOR_PURPLE "\033[1;35m"  // Purple
#define ANSI_COLOR_YELLOW "\033[1;33m"  // Yellow
#define ANSI_COLOR_ORANGE "\033[1;38;5;208m" // Orange
#define ANSI_COLOR_RED "\033[1;31m"     // Red
#define ANSI_COLOR_CYAN "\033[1;36m"    // Cyan
#define ANSI_COLOR_GREEN "\033[1;32m"   // Green

// Definição da estrutura de Pilha
typedef struct {
    double valores[MAX];
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
        p->valores[++(p->topo)] = valor;
    } else {
        printf("Estouro da pilha\n");
        exit(1);
    }
}

// Função para desempilhar um valor da pilha
double desempilhar(Pilha *p) {
    if (p->topo >= 0) {
        return p->valores[(p->topo)--];
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
        case '^': return pow(op1, op2); // Calcula op1 elevado a op2
        default:
            printf("Operador não suportado: %c\n", operador);
            exit(1);
    }
}

// Função para executar funções matemáticas
double executar_funcao(char *funcao, double op) {
    if (strcmp(funcao, "raiz") == 0) return sqrt(op); // Calcula a raiz quadrada de op
    else if (strcmp(funcao, "sen") == 0) return sin(op * M_PI / 180.0); // Calcula o seno de op (converte graus para radianos)
    else if (strcmp(funcao, "cos") == 0) return cos(op * M_PI / 180.0); // Calcula o cosseno de op (converte graus para radianos)
    else if (strcmp(funcao, "tg") == 0) return tan(op * M_PI / 180.0); // Calcula a tangente de op (converte graus para radianos)
    else if (strcmp(funcao, "log") == 0) return log10(op); // Calcula o logaritmo na base 10 de op
    else {
        printf("Função não suportada: %s\n", funcao);
        exit(1);
    }
}

// Função para avaliar uma expressão pós-fixada
double avaliar_posfixa(char *expressao) {
    Pilha pilha;
    inicializar(&pilha);
    char *token = strtok(expressao, " ");

    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            empilhar(&pilha, atof(token)); // Empilha números (convertidos de string para double)
        } else if (strlen(token) == 1 && strchr("+-*/^", token[0])) {
            double op2 = desempilhar(&pilha);
            double op1 = desempilhar(&pilha);
            double resultado = executar_operacao(token[0], op1, op2);
            empilhar(&pilha, resultado); // Empilha o resultado da operação
        } else {
            double op;
            if (strcmp(token, "cos") == 0 || strcmp(token, "sen") == 0 || strcmp(token, "tg") == 0 || strcmp(token, "log") == 0) {
                op = desempilhar(&pilha);
                double resultado = executar_funcao(token, op);
                empilhar(&pilha, resultado); // Executa funções matemáticas e empilha o resultado
            } else {
                op = atof(token);
                empilhar(&pilha, op); // Empilha números que não são funções matemáticas
            }
        }
        token = strtok(NULL, " ");
    }

    return desempilhar(&pilha); // Retorna o resultado final da expressão
}

// Função para imprimir o resultado com cor sequencial
void imprimir_resultado_colorido(char *expressao, double resultado, int indice_cor) {
    switch (indice_cor) {
        case 0:
            printf(ANSI_COLOR_PURPLE);
            break;
        case 1:
            printf(ANSI_COLOR_YELLOW);
            break;
        case 2:
            printf(ANSI_COLOR_ORANGE);
            break;
        case 3:
            printf(ANSI_COLOR_RED);
            break;
        case 4:
            printf(ANSI_COLOR_CYAN);
            break;
        case 5:
            printf(ANSI_COLOR_GREEN);
            break;
        default:
            printf(ANSI_COLOR_RESET);
            break;
    }

    printf("Resultado: %.2lf\n", resultado); // Imprime o resultado com a cor escolhida
    printf(ANSI_COLOR_RESET); // Reseta para a cor padrão
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

    char *expressoes[] = {expressao1, expressao2, expressao3, expressao4, expressao5, expressao6, expressao7, expressao8, expressao9};
    int num_expressoes = sizeof(expressoes) / sizeof(expressoes[0]);

    // Imprimir resultados coloridos para cada expressão
    for (int i = 0; i < num_expressoes; i++) {
        double resultado = avaliar_posfixa(expressoes[i]);
        printf("\n-----\n");
        printf("Expressão %d: %s\n", i + 1, expressoes[i]);
        imprimir_resultado_colorido(expressoes[i], resultado, i % 6); // Escolhe uma cor sequencial
    }

    return 0;
}

