#include <stdio.h>
#include <string.h>

#define MAX_NOME_ESTADO 20
#define QTD_ESTADOS 3

struct Estado{
    char nome[MAX_NOME_ESTADO];
    int numVeiculos;
    int numAcidentes;
};

void lerStr(char string[], int maxTam);
void coletarDados(struct Estado v[], int tam);
void maiorEMenorNumAcidentes(struct Estado v[], int tam, int *indiceMenor, int *indiceMaior);
int buscarEstado(struct Estado v[], int tam, char nomeEstado[]);
double percentualAcidentesEstado(struct Estado v[], int tam, char nomeEstado[]);
double mediaAcidentesPais(struct Estado v[], int tam);
void estadosAcimaDaMediaAcidentes(struct Estado v[], int tam, double numMediaAcidentesPais);

int main(){
    struct Estado estados[QTD_ESTADOS];
    int indiceMenor, indiceMaior;
    double numMediaAcidentesPais;

    coletarDados(estados, QTD_ESTADOS);
    maiorEMenorNumAcidentes(estados, QTD_ESTADOS, &indiceMenor, &indiceMaior);
    printf("O estado com menor numero de acidentes foi %s com %d acidentes.\n", estados[indiceMenor].nome, estados[indiceMenor].numAcidentes);
    printf("O estado com maior numero de acidentes foi %s com %d acidentes.\n", estados[indiceMaior].nome, estados[indiceMaior].numAcidentes);
    printf("O estado de Pernambuco teve um percentual de %.2lf\n", percentualAcidentesEstado(estados, QTD_ESTADOS, "Pernambuco")*100);
    numMediaAcidentesPais = mediaAcidentesPais(estados, QTD_ESTADOS);
    estadosAcimaDaMediaAcidentes(estados, QTD_ESTADOS, numMediaAcidentesPais);

    return 0;
}

void coletarDados(struct Estado v[], int tam){
    for(int i = 0; i < tam; i += 1){
        printf("Digite o nome do %d estado: ", i + 1);
        lerStr(v[i].nome, MAX_NOME_ESTADO);
        printf("Digite a quantidade de veiculos que rodam no estado: ");
        scanf("%d", &v[i].numVeiculos);
        getchar();
        printf("Digite a quantidade de acidentes no estado: ");
        scanf("%d", &v[i].numAcidentes);
        getchar();
    }
}

void maiorEMenorNumAcidentes(struct Estado v[], int tam, int *indiceMenor, int *indiceMaior){
    *indiceMenor = 0;
    *indiceMaior = 0;

    for(int i=1; i < tam; i+=1){
        if(v[i].numAcidentes < v[*indiceMenor].numAcidentes){
            *indiceMenor = i;
        }else if(v[i].numAcidentes > v[*indiceMaior].numAcidentes){
            *indiceMaior = i;
        }
    }
}

double percentualAcidentesEstado(struct Estado v[], int tam, char nomeEstado[]){
    int indiceEstado = buscarEstado(v, tam, nomeEstado);
    if(indiceEstado == -1){
        printf("Estado nao encontrado.");
        return 0;
    }

    return (double) v[indiceEstado].numAcidentes / v[indiceEstado].numVeiculos;
}

double mediaAcidentesPais(struct Estado v[], int tam){
    int soma;
    double media;
    for(int i = 0; i < tam; i+=1){
        soma += v[i].numAcidentes;
    }

    media = (double) soma / tam;
    return media;
}

void estadosAcimaDaMediaAcidentes(struct Estado v[], int tam, double numMediaAcidentesPais){
    for(int i = 0; i < tam; i+=1){
        double media = (double)v[i].numAcidentes/v[i].numVeiculos;
        if(media > numMediaAcidentesPais){
            printf("O estado %s possui media de %.2lf.\n", v[i].nome, media);
        }
    }
}

int buscarEstado(struct Estado v[], int tam, char nomeEstado[]){
    for(int i = 0; i < tam; i+=1){
        if(strcmp(nomeEstado, v[i].nome) == 0){
            return i;
        }
    }

    return -1;
}

void lerStr(char string[], int maxTam){
    fgets(string, maxTam, stdin);
    int tam = strlen(string);
    if(tam > 0 && string[tam-1] == '\n'){
        string[tam-1] = '\0';
    }
}