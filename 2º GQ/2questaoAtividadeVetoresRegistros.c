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
int buscarProduto(struct Produto produtos[], int tam, int id);
void alterarValorUnitario(struct Produto produtos[], int tam);
double mostrarValorUnitario(struct Produto produtos[], int tam);

int main() {
    struct Produto produtos[TAM];
    int totalProdutos = 0;
    int opcao;

    do {
        printf("\n======== PAPELARIA ESCOLAR ========\n");
        printf("1. Cadastrar novo produto\n");
        printf("2. Mudar valor de um produto\n");
        printf("3. Exibir valor de um produto\n");
        printf("7. Exibir todos os produtos\n");
        printf("-----------------------------------\n");
        printf("Escolha uma opcao (0 para sair): ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarProduto(produtos, &totalProdutos);
                break;
            case 2:
                alterarValorUnitario(produtos, TAM);
                break;
            case 3:
                mostrarValorUnitario(produtos, TAM);
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
    printf("%-10s | %-30s | %s\n", "Codigo", "Descricao", "Valor");
    printf("------------------------------------------\n");
    for (int i = 0; i < n; i += 1) {
        printf("%-10d | %-30s | %.2lf\n", produtos[i].codigo, produtos[i].descricao, produtos[i].vlrUnit);
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
        if(produtos[i].codigo == id){
            return i;
        }
    }

    return -1;
}

void alterarValorUnitario(struct Produto produtos[], int tam){
    int index, idProduto;
    index = buscarProduto(produtos, tam, idProduto);

    printf("Digite o codigo do produto que deseja alterar o valor: ");
        scanf("%d", &idProduto);
    if(index == -1){
        printf("Produto não encontrado.");
        return;
    }

    printf("Digite o novo valor: ");
    scanf("%lf", &produtos[index].vlrUnit);

    printf("Produto alterado com sucesso");
}

double mostrarValorUnitario(struct Produto produtos[], int tam){
    int index, codigo;

    printf("Digite o codigo do produto: ");
    scanf("%d", &codigo);
    index = buscarProduto(produtos, tam, codigo);
    if(index = -1){
        printf("Produto não encontrado.");
        return;
    }

    printf("%s: %.2lf", produtos[index].descricao, produtos[index].vlrUnit);
}