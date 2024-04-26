#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float X;
    float Y;
} Ponto;

// Função para calcular a área de um triângulo usando o determinante
float calcularAreaTriangulo(Ponto p1, Ponto p2, Ponto p3) {
    return abs((p1.X*(p2.Y-p3.Y) + p2.X*(p3.Y-p1.Y) + p3.X*(p1.Y-p2.Y)) / 2.0);
}

// Função para ler os pontos do arquivo e calcular a área do polígono
float calcularAreaPoligono(char *filename) {
    FILE *file;
    int numVertices, i;
    float areaTotal = 0.0;
    Ponto *pontos;

    // Abre o arquivo
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    // Lê o número de vértices
    fscanf(file, "%d", &numVertices);

    // Aloca memória para armazenar os pontos
    pontos = (Ponto *)malloc(numVertices * sizeof(Ponto));
    if (pontos == NULL) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }

    // Lê os pontos
    for (i = 0; i < numVertices; i++) {
        fscanf(file, "%f,%f", &pontos[i].X, &pontos[i].Y);
    }

    // Fecha o arquivo
    fclose(file);

    // Calcula a área do polígono dividindo-o em triângulos
    for (i = 1; i < numVertices - 1; i++) {
        areaTotal += calcularAreaTriangulo(pontos[0], pontos[i], pontos[i+1]);
    }

    // Libera a memória alocada para os pontos
    free(pontos);

    return areaTotal;
}

int main() {
    float area;

    // Chama a função para calcular a área do polígono
    area = calcularAreaPoligono("pontos.txt");

    // Exibe a área calculada
    printf("A area do poligono eh: %.2f\n", area);

    return 0;
}
