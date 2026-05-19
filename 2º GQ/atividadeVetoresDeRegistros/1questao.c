#include <stdio.h>

#define TAM_MAX_NOME 20
#define QTD_ESTADOS 2

struct Estado{
    char nome[TAM_MAX_NOME];
    int numAcidentes;
    int numVeiculos;
};

void preencherEstado(struct Estado *estado);
void preencherVetorEstados(struct Estado ve[QTD_ESTADOS], int tam);

int main(){
    struct Estado estados[QTD_ESTADOS];

    preencherVetorEstados(estados, QTD_ESTADOS);

    return 0;
}

void preencherEstado(struct Estado *estado){
    printf("Digite o nome do estado: ");
    scanf("%s", estado->nome);
    printf("\nDigite o número de acidentes de trânsito no estado: ");
    scanf("%d", &estado->numAcidentes);
    printf("\nDigite o número de veículos registrados no estado: ");
    scanf("%d", &estado->numVeiculos);
}

void preencherVetorEstados(struct Estado ve[QTD_ESTADOS], int tam){
    for(int i = 0; i < tam; i += 1){
        printf("Digitação do %d estado\n", i + 1);
        preencherEstado(&ve[i]);
    }
}