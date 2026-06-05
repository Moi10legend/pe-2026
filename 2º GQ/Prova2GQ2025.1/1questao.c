#include <stdio.h>
#include <string.h>

struct Produto{
    int id;
    char descricao[20];
    int qtdEstoque;
    float vlrUnit;
};

struct Venda{
    int id;
    int qtdProdutosVendidos;
    int idsProdutos[5];
    int qtdsVendidas;
};

void lerStr(char str[], int tamMax);

int main(){

    return 0;
}

int buscaSequencialDesc(struct Produto v[], int tam, char x[]){
    int i;
    for(i; i < tam; i+=1){
        if(strcmp(v[i].descricao, x) == 0){
            return i;
        }
    }

    return -1;
}

int buscaBinariaId(struct Venda v[], int tam, int x){
    int inicio = 0, meio, fim = tam - 1;

    do{
        meio = (inicio + fim) / 2;
        if(v[meio].id > x){
            fim = meio - 1;
        }else{
            inicio = meio + 1;
        }
    }while(x != v[meio].id && inicio <= fim);

    if(x == v[meio].id){
        return meio;
    }
    else{
        return -1;
    }
}

int alteraProduto(struct Venda v[], int tam){
    char descricaoProcurada[20];
    printf("Digite a descrição do produto que deseja alterar: ");
    scanf("% [^\n]", descricaoProcurada);
    getchar();

    
}

void venda(struct Produto vp[], int tamProd, struct Venda vv[], int tamVendas){
    int id, qtdProdutosVendidos;
    printf("Digite o ID da venda: ");
    scanf("%d", &id);
    if(buscaBinariaId(vv, tamVendas, id) != -1){
        printf("Id ja cadastrado.");
        return;
    }

    printf("Digite a quantidade de produtos diferentes que serao vendidos (1 a 5): ");
    scanf("%d", &qtdProdutosVendidos);
    vv[tamVendas].qtdProdutosVendidos = qtdProdutosVendidos;
    for(int i = 0; i < qtdProdutosVendidos; i+=1){
        char descricaoProduto[20];
        int posicaoProd, qtdVendidasProduto;
        printf("Digite a descricao do %d produto: ", i + 1);
        lerStr(descricaoProduto, 20);
        posicaoProd = buscaSequencialDesc(vp, tamProd, descricaoProduto);
        if(posicaoProd == -1){
            printf("Produto nao encontrado.");
            return;
        };
        vv[tamVendas].idsProdutos[i] = vp[posicaoProd].id;

        printf("Digite a quantidade de unidades vendidas desse produto: ");
        scanf("%d", &qtdVendidasProduto);
        if(vp[posicaoProd].qtdEstoque < qtdVendidasProduto){
            printf("Não possui essa quantidade em estoque.");
            return;
        }
        vv[tamVendas].qtdsVendidas += qtdVendidasProduto;
        vp[posicaoProd].qtdEstoque -= qtdVendidasProduto;
    }
}

void relatorio(struct Produto vp[], int tamProd, struct Venda vv[], int tamVenda){
    for(int i = 0; i < tamVenda; i+=1){
        printf("Venda %d\n", i+1);
        
    }
}

void lerStr(char str[], int tamMax){
    fgets(str, tamMax, stdin);
    int tam = strlen(str);
    if(tam > 0 && str[tam-1] == '\n'){
        str[tam-1] = '\0';
    }
}