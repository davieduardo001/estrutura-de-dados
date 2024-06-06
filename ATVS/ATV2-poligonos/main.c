#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um ponto no plano
typedef struct {
    float X;
    float Y;
} Ponto;

// Função para calcular a área de um triângulo dado seus vértices A, B e C
float AreaTriangulo(Ponto A, Ponto B, Ponto C) {
    return 0.5 * ((A.X * (B.Y - C.Y)) + (B.X * (C.Y - A.Y)) + (C.X * (A.Y - B.Y)));
}

// Função para calcular a área total de um polígono
float AreaPoligono(Ponto* vertices, int numVertices) {
    float area = 0.0;
    int i;

    // Se o polígono tem menos de 3 vértices, não é possível formar triângulos
    if (numVertices < 3) {
        printf("Polígono inválido!\n");
        return 0.0;
    }

    // Calcular a área do polígono decompondo-o em triângulos
    for (i = 1; i < numVertices - 1; i++) {
        area += AreaTriangulo(vertices[0], vertices[i], vertices[i + 1]);
    }

    return area;
}

int main() {
    FILE *arquivo;
    int numVertices, i;
    Ponto *vertices;

    // Abre o arquivo de entrada
    arquivo = fopen("poligono.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Lê o número de vértices do polígono
    fscanf(arquivo, "%d", &numVertices);

    // Aloca memória para armazenar os vértices do polígono
    vertices = (Ponto*)malloc(numVertices * sizeof(Ponto));
    if (vertices == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1;
    }

    // Lê as coordenadas dos vértices do polígono a partir do arquivo
    for (i = 0; i < numVertices; i++) {
        fscanf(arquivo, "%f %f", &vertices[i].X, &vertices[i].Y);
    }

    // Fecha o arquivo
    fclose(arquivo);

    // Calcula a área do polígono
    float area = AreaPoligono(vertices, numVertices);

    // Exibe a área calculada
    printf("Área do polígono: %.2f unidades quadradas\n", area);

    // Libera a memória alocada para os vértices
    free(vertices);

    return 0;
}
