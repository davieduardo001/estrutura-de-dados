#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOTA_DE_CORTE 7.0

typedef struct {
    char nome[100];
    char telefone[100];
    char curso[100];
    float nota1; 
    float nota2;
    char *consideracaoFinal;
} Aluno;

void lerCSV(const char *filename) {
    FILE *entrada = fopen(filename, "r");
    FILE *saida = fopen("saida.csv", "w");

    if (entrada == NULL || saida == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    char line[20000];

    // Lê a primeira linha que contém os cabeçalhos dos campos (nome, telefone, curso, nota1, nota2)
    fgets(line, sizeof(line), entrada);

    printf("Nome,Media,Aprovado\n");

    // Lê cada linha subsequente
    while (fgets(line, sizeof(line), entrada)) {

        Aluno aluno;

        // NOME
        char *token = strtok(line, ",");
        strcpy(aluno.nome, token);

        // TELEFONE       
        token = strtok(NULL, ",");
        strcpy(aluno.telefone, token);

        // CURSO
        token = strtok(NULL, ",");
        strcpy(aluno.curso, token);

        // NOTA 1
        token = strtok(NULL, ",");
        aluno.nota1 = atof(token);

        // NOTA 2
        token = strtok(NULL, ",");
        aluno.nota2 = atof(token);

        // Calcula a média
        double media = (double)(aluno.nota1 + aluno.nota2) / 2.0;

        // Verifica se o aluno foi aprovado ou reprovado
        aluno.consideracaoFinal = (media >= NOTA_DE_CORTE) ? "APROVADO" : "REPROVADO";

        // string formatada com NOME+MEDIA+CONSIDERACAO_FINAL
        char string_formatada[100000];
        sprintf(string_formatada, "%s,%.2lf,%s", aluno.nome, (double)media, aluno.consideracaoFinal);

        // Envio para o output
        printf("%s\n", string_formatada);
        fprintf(saida, "%s\n", string_formatada);
    }

    fclose(saida);
    fclose(entrada);
}

int main() {
    lerCSV("dados.csv");

    return 0;
}