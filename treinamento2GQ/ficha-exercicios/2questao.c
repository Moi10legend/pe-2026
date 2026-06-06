#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 40
#define MAX_DESCRICAO 50

struct Produto{
    int codigo;
    char descricao[MAX_DESCRICAO];
    double vlrUnit;
    int qtdEstoque;
};

void lerStr(char str[], int tamMax);
void cadastrarProduto(struct Produto v[], int tam);
int buscarProduto(struct Produto v[], int tam, int codigo);
void alterarValorUnitario(struct Produto v[], int tam, int codigo);
double informarValorUnitario(struct Produto v[], int tam, int codigo);
int informarQtdEstoque(struct Produto v[], int tam, int codigo);
void venda(struct Produto v[], int tam, int codigo, int qtdVenda);
void atualizarQtdEstoque(struct Produto v[], int tam, int codigo);

int main(){
    struct Produto produtos[MAX_PRODUTOS];
    int tamProdutos = 0;

    return 0;
}

void cadastrarProduto(struct Produto v[], int tam){
    printf("Digite o codigo do produto: ");
    scanf("%d", &v[tam].codigo);
    getchar();
    printf("Digite a descricao do produto: ");
    lerStr(v[tam].descricao, MAX_DESCRICAO);
    printf("Digite o valor unitario do produto: ");
    scanf("%lf", &v[tam].vlrUnit);
    getchar();
    printf("Digite a quantidade em estoque do produto: ");
    scanf("%d", &v[tam].qtdEstoque);
    getchar();
}

void alterarValorUnitario(struct Produto v[], int tam, int codigo){
    int indiceProduto = buscarProduto(v, tam, codigo);
    if(indiceProduto == -1){
        printf("Produto nao encontrado");
        return;
    }

    printf("Digite o novo valor unitario de %s: ", v[indiceProduto].descricao);
    scanf("%lf", &v[indiceProduto].vlrUnit);
    getchar();

    printf("Valor alterado com sucesso.");
}

double informarValorUnitario(struct Produto v[], int tam, int codigo){
    int indiceProduto = buscarProduto(v, tam, codigo);

    if(indiceProduto == -1){
        printf("Produto nao encontrado");
        return -1;
    }

    return v[indiceProduto].vlrUnit;
}

int informarQtdEstoque(struct Produto v[], int tam, int codigo){
    int indiceProduto = buscarProduto(v, tam, codigo);

    if(indiceProduto == -1){
        printf("Produto nao encontrado.");
        return -1;
    }

    return v[indiceProduto].qtdEstoque;
}

void venda(struct Produto v[], int tam, int codigo, int qtdVenda){
    int indiceProduto = buscarProduto(v, tam, codigo);
    int confirmacaoCompra;
    if(indiceProduto == -1){
        printf("Produto nao encontrado.");
        return;
    }

    if(v[indiceProduto].qtdEstoque == 0){
        printf("Produto sem disponibilidade no estoque.");
        return;
    }

    if(qtdVenda <= v[indiceProduto].qtdEstoque){
        printf("Valor: %.2lf", v[indiceProduto].vlrUnit*qtdVenda);
        printf("Deseja efetivar a compra? (1 para sim, 0 para nao): ");
        scanf("%d", &confirmacaoCompra);
        getchar();

        v[indiceProduto].qtdEstoque -= qtdVenda;
        return;
    }

    printf("Quantidade acima da disponivel em estoque.");
}

void atualizarQtdEstoque(struct Produto v[], int tam, int codigo){
    int indiceProduto = buscarProduto(v, tam, codigo);

    printf("Digite a nova quantidade em estoque: ");
    scanf("%d", &v[indiceProduto].qtdEstoque);
    getchar();
}

void codigoEDescricaoTodos(struct Produto v[], int tam){

}

void codigoEDescricaoProdutos0Estoque(struct Produto v[], int tam){
    
}

int buscarProduto(struct Produto v[], int tam, int codigo){
    for(int i = 0; i < tam; i+=1){
        if(v[i].codigo == codigo){
            return i;
        }
    }

    return -1;
}

void lerStr(char str[], int tamMax){
    fgets(str, tamMax, stdin);
    int tam = strlen(str);
    if(tam > 0 && str[tam-1] == '\n'){
        str[tam-1] = '\0';
    }
}