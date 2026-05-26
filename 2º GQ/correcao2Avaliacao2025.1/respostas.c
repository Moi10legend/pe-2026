#include <stdio.h>
#include <string.h>

#define TAM 100

struct Categoria{
    int codigo;
    char nome[50];
};

struct Produto{
    int codigo;
    char titulo[100];
    char descricao[256];
    int categoria;
    int preco;
};

void CadastrarCategoria(struct Categoria v[], int *qtd);
int buscarCategoria(struct Categoria v[], int qtd, int codigo);
void imprimirCategorias(struct Categoria v[], int qtd);
void imprimirProdutos(struct Produto vp[], int qtdProdutos, struct Categoria vc[], int qtdCategorias);
void selectionSortPorDescricao(struct Produto v[], int qtd);
int buscaBinariaPorDescricao(struct Produto v[], int qtd, char *x);

int main(){
    int qtdProdutos = 16, qtdCategorias = 4;
    struct Categoria categorias[TAM] = {
        {1, "Perifericos"},
        {2, "Moveis Gamers"},
        {3, "Hardware"},
        {4, "Videogames"}
    };
    struct Produto produtos[TAM] = {
        {101, "Mouse Gamer", "Mouse optico com led rgb", 1, 15000},          
        {102, "Teclado Mecanico", "Teclado mecanico switch azul", 1, 25000}, 
        {103, "Monitor 24", "Monitor full hd 75hz", 1, 80000},               
        {104, "Cadeira Gamer", "Cadeira ergonomica preta e vermelha", 2, 120000},
        {105, "Headset", "Headset com microfone antirruido", 1, 18000},
        {106, "Mousepad", "Mousepad gigante 90x40", 1, 5000},
        {107, "Placa de Video", "Placa de video rtx 3060", 3, 250000},
        {108, "Processador", "Processador octa core 4.0 ghz", 3, 150000},
        {109, "Memoria RAM", "Memoria ddr4 16gb rgb", 3, 35000},
        {110, "SSD", "Ssd nvme 1tb alta velocidade", 3, 45000},
        {111, "Fonte", "Fonte atx 650w 80 plus bronze", 3, 30000},
        {112, "Gabinete", "Gabinete de vidro temperado", 3, 28000},
        {113, "Webcam", "Webcam full hd 1080p", 1, 12000},
        {114, "Microfone", "Microfone condensador usb", 1, 22000},
        {115, "Suporte Monitor", "Suporte articulado para dois monitores", 2, 15000},
        {116, "PS5", "Videogame ultima geracao", 4, 500000}
    };
    char descricaoProcurada[256] = "Videogame ultima geracao";

    CadastrarCategoria(categorias, &qtdCategorias);
    imprimirCategorias(categorias, qtdCategorias);
    imprimirProdutos(produtos, qtdProdutos, categorias, qtdCategorias);
    selectionSortPorDescricao(produtos, qtdProdutos);
    imprimirProdutos(produtos, qtdProdutos, categorias, qtdCategorias);
    printf("\n%d", buscaBinariaPorDescricao(produtos, qtdProdutos, descricaoProcurada));
    return 0;
}

void CadastrarCategoria(struct Categoria v[], int *qtd){
    if(TAM == *qtd){
        printf("Limite de categorias cadastradas atingido.");
        return;
    }

    int ehPossivel = 1;
    while(ehPossivel){
        printf("Digite o numero do codigo da categoria: ");
        int codigo;
        scanf("%d", &codigo);
        if(buscarCategoria(v, *qtd, codigo) != -1){
            printf("Codigo ja cadastrado.");
            continue;
        }
        v[*qtd].codigo = codigo;
        printf("Digite o nome da categoria: ");
        scanf("%s", v[*qtd].nome);
        *qtd += 1;
        printf("Categoria cadastrada com sucesso.");
        ehPossivel = 0;
    }
}

void imprimirCategorias(struct Categoria v[], int qtd){
    for(int i = 0; i < qtd; i += 1){
        printf("\nCodigo: %d", v[i].codigo);
        printf("\nNome: %s", v[i].nome);
    }
}

int buscarCategoria(struct Categoria v[], int qtd, int codigo){
    for(int i = 0; i < qtd; i += 1){
        if(v[i].codigo == codigo){
            return i;
        }
    }
    return -1;
}

void imprimirProdutos(struct Produto vp[], int qtdProdutos, struct Categoria vc[], int qtdCategorias){
    for(int i = 0; i < qtdProdutos; i += 1){
        printf("\nCodigo: %d", vp[i].codigo);
        printf("\nTitulo: %s", vp[i].titulo);
        printf("\nDescricao: %s", vp[i].descricao);
        printf("\nCategoria: %s", vc[buscarCategoria(vc, qtdCategorias, vp[i].categoria)].nome);
        printf("\nPreco: %.2lf", vp[i].preco/100.0);
    }
}

void selectionSortPorDescricao(struct Produto v[], int qtd){
    int menor;
    struct Produto aux;
    for(int i = 0; i < qtd-1; i+=1){
        menor = i;
        for(int j = i + 1; j <= qtd-1; j+=1){
            if(strcmp(v[j].descricao, v[menor].descricao) < 0){
                menor = j;
            }
        }
        aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;
    }
}

int buscaBinariaPorDescricao(struct Produto v[], int qtd, char *x){
    int inicio = 0, meio, fim = qtd-1;
    do{
        meio = (inicio + fim) / 2;
        if(strcmp(v[meio].descricao, x) > 0){
            fim = meio - 1;
        }else{
            inicio = meio + 1;
        }
    }while(strcmp(v[meio].descricao, x) != 0 && inicio <= fim);
    
    if(strcmp(v[meio].descricao, x) == 0){
        return meio;
    }else if(qtd == 0){
        return -2;
    }else{
        return -1;
    }
}