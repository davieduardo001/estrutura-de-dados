#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Pessoa {
    char Nome[1024];
    int Idade;
    float Altura;
    float Peso;
};

struct Pessoa criarPessoa(); // referente a um "constructor"
float calcularIMC(struct Pessoa X);
void atualizarIdade(struct Pessoa *X); 
void exibirPessoa(struct Pessoa X);

int main() {
    system("clear");

    struct Pessoa pessoa = criarPessoa();
    
    exibirPessoa(pessoa);

    printf("imc: %.3f\n", calcularIMC(pessoa));

    atualizarIdade(&pessoa);

    printf("atualizado:\n");
    exibirPessoa(pessoa);    
    return 0;
}

struct Pessoa criarPessoa() {
    struct Pessoa X;

    printf("Digite o nome: ");
    scanf("%s", X.Nome);
    printf("Digite a sua idade: ");
    scanf("%d", &X.Idade);
    printf("Digite sua altura: ");
    scanf("%f", &X.Altura);
    printf("Digite o peso: ");
    scanf("%f", &X.Peso);

    return(X);
}

float calcularIMC(struct Pessoa X) {
    float R = X.Peso/(X.Altura*X.Altura);

    return(R);
}

void atualizarIdade(struct Pessoa *X) {
    X->Idade = X->Idade + 1;
}

void exibirPessoa(struct Pessoa X) {
    printf("-------------printando-----------------\n");
    printf("nome: %s\nidade: %d\naltura: %.2f\npeso: %.2f\n", X.Nome, X.Idade, X.Altura, X.Peso);
    printf("--------------------------------\n");
}