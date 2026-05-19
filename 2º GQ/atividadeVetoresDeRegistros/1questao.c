#include <stdio.h>
#include <string.h>

#define TAM_MAX_NOME 20
#define QTD_ESTADOS 26

struct Estado{
    char nome[TAM_MAX_NOME];
    int numAcidentes;
    int numVeiculos;
};

void preencherEstado(struct Estado *estado);
void preencherVetorEstados(struct Estado ve[QTD_ESTADOS], int tam);
void menorEMaiorNumeroDeAcidentes(struct Estado ve[], int tam, int *indiceMenor, int *indiceMaior);
double percentualDeVeiculosEnvolvidosEmAcidentes(struct Estado ve[], char nomeEstado[], int tam);
double mediaAcidentesNacional(struct Estado ve[], int tam);
void estadosAcimaDaMediaNacionalDeAcidentes(struct Estado ve[], int tam, double media);

int main(){
    struct Estado estados[QTD_ESTADOS];
    int menor, maior;
    double percentualVeiculosAcidentes, mediaAcidentesNoPais;
    char estado[TAM_MAX_NOME];

    preencherVetorEstados(estados, QTD_ESTADOS);
    menorEMaiorNumeroDeAcidentes(estados, QTD_ESTADOS, &menor, &maior);
    printf("O estado com maior número de acidentes é %s com %d acidentes", 
        estados[maior].nome, estados[maior].numAcidentes);
    printf("\nO estado com menor número de acidentes é %s com %d acidentes.",
        estados[menor].nome, estados[menor].numAcidentes);
    
    printf("\nDigite o nome do estado que deseja ver o percentual de veículos que se envolveram em acidentes: ");
    scanf(" %[^\n]", estado);

    percentualVeiculosAcidentes = percentualDeVeiculosEnvolvidosEmAcidentes(estados,estado, QTD_ESTADOS) * 100;
    printf("\nO estado %s tem %.2lf%% de veículos envolvidos em acidentes.\n", estado, percentualVeiculosAcidentes);
    
    mediaAcidentesNoPais = mediaAcidentesNacional(estados, QTD_ESTADOS);
    printf("\nA média nacional de acidentes é de %.2lf\n", mediaAcidentesNoPais);

    estadosAcimaDaMediaNacionalDeAcidentes(estados, QTD_ESTADOS, mediaAcidentesNoPais);
    
    return 0;
}

void preencherEstado(struct Estado *estado){
    printf("Digite o nome do estado: ");
    scanf(" %[^\n]", estado->nome);
    printf("Digite o número de veículos registrados no estado: ");
    scanf("%d", &estado->numVeiculos);
    printf("Digite o número de acidentes de trânsito no estado: ");
    scanf("%d", &estado->numAcidentes);
}

void preencherVetorEstados(struct Estado ve[], int tam){
    for(int i = 0; i < tam; i += 1){
        printf("Digitação do %d estado\n", i + 1);
        preencherEstado(&ve[i]);
    }
}

void menorEMaiorNumeroDeAcidentes(struct Estado ve[], int tam, int *indiceMenor, int *indiceMaior){
    *indiceMenor = 0; 
    *indiceMaior = 0;

    for(int i = 1; i < tam; i += 1){
        if(ve[i].numAcidentes > ve[*indiceMaior].numAcidentes){
            *indiceMaior = i;
        }
        if(ve[i].numAcidentes < ve[*indiceMenor].numAcidentes){
            *indiceMenor = i;
        }
    }
}

double percentualDeVeiculosEnvolvidosEmAcidentes(struct Estado ve[], char nomeEstado[], int tam){
    for(int i = 0; i < tam; i += 1){
        if(strcmp(ve[i].nome, nomeEstado) == 0){
            return (double) ve[i].numAcidentes / ve[i].numVeiculos; 
        }
    }

    return -1;
}

double mediaAcidentesNacional(struct Estado ve[], int tam){
    int soma = 0;
    double media = 0;

    for(int i = 0; i < tam; i += 1){
        soma += ve[i].numAcidentes;
    }

    media = (double) soma / tam;
    return media;
}

void estadosAcimaDaMediaNacionalDeAcidentes(struct Estado ve[], int tam, double media){
    int contadorVetorAcimaMedia = 0;
    for(int i = 0; i < tam; i += 1){
        if(ve[i].numAcidentes > media){
            printf("\nEstado %s acima da média com %d acidentes\n", ve[i].nome, ve[i].numAcidentes);
        }
    }
}