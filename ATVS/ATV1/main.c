#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOTA_DE_CORTE 7.0

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
        char *token = strtok(line, ",");
        float nota1, nota2;
        char nome[50];
        // Ignora o campo nome (primeiro campo)
        strcpy(nome, token);
        // Pula para o próximo campo
        token = strtok(NULL, ",");
        // Ignora o campo telefone (segundo campo)
        // Pula para o próximo campo
        token = strtok(NULL, ",");
        // Ignora o campo curso (terceiro campo)
        // Pula para o próximo campo
        token = strtok(NULL, ",");
        // Lê a nota1 (quarto campo)
        nota1 = atof(token);
        // Pula para o próximo campo
        token = strtok(NULL, ",");
        // Lê a nota2 (quinto campo)
        nota2 = atof(token);

        // Calcula a média
        float media = (nota1 + nota2) / 2.0;

        // Verifica se o aluno foi aprovado ou reprovado
        const char *aprovado = (media >= NOTA_DE_CORTE) ? "APROVADO" : "REPROVADO";

        // string formtada:
        char string_formatada[100];
        sprintf(string_formatada, "%s,%.f,%s", nome, media, aprovado);
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