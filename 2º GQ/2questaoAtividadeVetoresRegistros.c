#include <stdio.h>
#include <string.h>

#define TAM 40
#define TAM_DESC 100

struct Produto {
    int codigo;
    char descricao[TAM_DESC];
    double vlrUnit;
    int qtdEst;
};

void cadastrarProduto(struct Produto produtos[], int *n);
void exibirProdutos(struct Produto produtos[], int n);
void lerStr(char str[], int tamMax);

int main() {
    struct Produto produtos[TAM];
    int totalProdutos = 0;
    int opcao;

    do {
        printf("\n======== PAPELARIA ESCOLAR ========\n");
        printf("1. Cadastrar novo produto\n");
        printf("7. Exibir todos os produtos\n");
        printf("-----------------------------------\n");
        printf("Escolha uma opcao (0 para sair): ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarProduto(produtos, &totalProdutos);
                break;
            case 7:
                exibirProdutos(produtos, totalProdutos);
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

// (a) Um procedimento para cadastrar um novo produto
void cadastrarProduto(struct Produto produtos[], int *n) {
    char tempStr[TAM_DESC];
    
    if (*n >= TAM) {
        printf("\nErro: Capacidade maxima de cadastro atingida (%d).\n", TAM);
        return;
    }

    printf("\n--- Cadastro de Produto ---\n");
    printf("Codigo: ");
    scanf("%d", &produtos[*n].codigo);
    
    lerStr(tempStr, TAM_DESC); // remover o ENTER do buffer
    printf("Descricao: ");
    lerStr(produtos[*n].descricao, TAM_DESC);

    printf("Valor Unitario: ");
    scanf("%lf", &produtos[*n].vlrUnit);

    printf("Quantidade em Estoque: ");
    scanf("%d", &produtos[*n].qtdEst);

    *n += 1;
    printf("Produto cadastrado com sucesso!\n");
}

// (g) Um procedimento para exibir o código e a descrição de todos os produtos
void exibirProdutos(struct Produto produtos[], int n) {
    if (n == 0) {
        printf("\nNenhum produto cadastrado.\n");
        return;
    }

    printf("\n--- Relatorio de Produtos ---\n");
    printf("%-10s | %-30s\n", "Codigo", "Descricao");
    printf("------------------------------------------\n");
    for (int i = 0; i < n; i += 1) {
        printf("%-10d | %-30s\n", produtos[i].codigo, produtos[i].descricao);
    }
}

void lerStr(char str[], int tamMax) {
    fgets(str, tamMax, stdin);
    int tam = strlen(str);
    if (tam > 0 && str[tam - 1] == '\n') {
        str[tam - 1] = '\0';
    }
}

int buscarProduto(struct Produto produtos[], int tam, int id){
    for(int i = 0; i < tam; i+=1){
        if(produtos[i]){
            
        }
    }
}