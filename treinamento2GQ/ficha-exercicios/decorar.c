#include <stdio.h>
#include <string.h>

void lerStr(char str[], int tamMax){
    fgets(str, tamMax, stdin);
    int tam = strLen(str);
    if(tam > 0 && str[tam-1] == '\n'){
        str[tam-1] = '\0';
    }
}

int buscaBinaria(int v[], int tam, int chave){
    int inicio = 0, meio, fim = tam-1;

    do{
        meio = (inicio+fim)/2;
        if(v[meio] > chave){
            fim = meio - 1;
        }else{
            inicio = meio + 1;
        }
    }while(v[meio] != chave && inicio <= fim);

    if(v[meio] == chave){
        return meio;
    }

    return -1;
}

void insercaoDireta(int v[], int tam){
    int aux, j;
    for(int i = 1; i < tam; i+=1){
        aux = v[i];
        j = i-1;
        while(j >= 0 && v[j] > v[j+1]){
            v[j+1] = v[j];
            j = j - 1;
        }
        v[j+1] = aux;
    }
}

void selecaoOrdenada(int v[], int tam){
    int menor, aux;

    for(int i = 0; i < tam - 1; i+=1){
        menor = v[i];
        for(int j = i+1; j < tam; j+=1){
            if(v[j] > v[menor]){
                menor = j;
            }
        }
        aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;
    }
}