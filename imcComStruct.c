#include <stdio.h>
#include <string.h>

#define TAM_NOME 30

struct Pessoa {
    char nome[TAM_NOME];
    int idade;
    double peso, altura;
};

void lerStr(char str[], int tamMax);
void imprimirPessoa(struct Pessoa p);
void preencherPessoa(struct Pessoa *p);
void calcularImc(struct Pessoa p);

int main() {
    struct Pessoa pessoa;
    printf("---------digitação------------\n");
    preencherPessoa(&pessoa);
    printf("---------impressão------------\n");
    imprimirPessoa(pessoa);
    printf("---------imc------------\n");
    calcularImc(pessoa);
    return 0;
}

void imprimirPessoa(struct Pessoa p) {
    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
    printf("Peso: %.2lf\n", p.peso);
    printf("Altura: %.2lf\n", p.altura);
}

void preencherPessoa(struct Pessoa *p) {
    printf("Digite o nome:\n");
    lerStr(p->nome, TAM_NOME);
    printf("Digite a idade:\n");
    scanf("%d", &p->idade);
    printf("Digite o peso:\n");
    scanf("%lf", &p->peso);
    printf("Digite a altura:\n");
    scanf("%lf", &p->altura);
}

// como referência apenas - notação menos utilizada
void preencherPessoa2(struct Pessoa *p) {
    printf("Digite o nome:\n");
    lerStr((*p).nome, TAM_NOME);
    printf("Digite a idade:\n");
    scanf("%d", &(*p).idade);
    printf("Digite o peso:\n");
    scanf("%lf", &(*p).peso);
    printf("Digite a altura:\n");
    scanf("%lf", &(*p).altura);
}

void lerStr(char str[], int tamMax) {
    fgets(str, tamMax, stdin);
    int tam = strlen(str);
    if (tam > 0 && str[tam - 1] == '\n') {
        str[tam - 1] = '\0';
    }
}

void calcularImc(struct Pessoa p){
    double imc = 0;
    imc = p.peso/(p.altura*p.altura);
    printf("O imc de %s é: %.2lf", p.nome, imc);
}