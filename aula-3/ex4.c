#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void exibirVetor(int V[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d\t", V[i]);
    }

    size = 2*size - 'd';
    printf("size (dentro da func): %d\n", size);
}

void modificarVetor(int *V, int size) {
    for(int i = 0; i < size; i++) {
        V[i] = V[i] * 2;
    }
}

void testarVetor(int *V, int size) {
    printf("%p\n", V); // retorna o endereco de mem do vetor
    V++;
    printf("%p\n", V); // retorna o endereco de mem do vetor
    V++;
    printf("%p\n", V); // retorna o endereco de mem do vetor


    printf("testando..\n\n");
    for(int i = 0; i < size; i++) {
        printf("%p\n", &V[i]);
    }
}

int *criarArr(int tamanho) {
    int *arr = malloc(tamanho * sizeof(int));
    for(int i = 0; i < tamanho; i++) arr[i] = i + 1;
    return arr;
}

int main() {
    system("clear");

    int tamanho;
    printf("digite o tamanho do vetor: ");
    int *myarr = criarArr(tamanho);
    printf()

    int V[] = {3, 1, 4, 1, 4, 5, 1};
    int size = (int)(sizeof(V)/sizeof(int));
    printf("size of the vetor: %d\n", size); // em C eh necessario fazer a divisao para coletar o tamanho do vetor

    exibirVetor(V, size);
    modificarVetor(V, size);
    exibirVetor(V, size);

    printf("testando vetor: \n");
    testarVetor(V, size);

    printf("\n");

    return 0;
}