#include <stdio.h>

#define TAM_DESCRICAO 30
#define MAX_PRODUTOS 40

struct Produto{
    int codigo;
    char descricao[TAM_DESCRICAO];
    double valorUnit;
    int qtdEst;
};

int main(){
    struct Produto produtos[MAX_PRODUTOS]; 

    return 0;
}

void cadastrarProduto(struct Produto p[]){
    
}