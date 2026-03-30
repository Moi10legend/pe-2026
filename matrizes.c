#include <stdio.h>
#include <stdlib.h>

#define LIN 5
#define COL 8

void preencherMatriz(int m[][COL], int lin, int col);
void preencherMatrizAleatorio(int m[][COL], int lin, int col);
void imprimirMatriz(int m[][COL], int lin, int col);
void maiorValorMatriz(int m[][COL], int lin, int col);
void menorValorMatriz(int m[][COL], int lin, int col);

int main() {
    int m[LIN][COL];
    srand(2);
    preencherMatrizAleatorio(m, LIN, COL);
    printf("\nMatriz digitada\n");
    imprimirMatriz(m, LIN, COL);
    maiorValorMatriz(m, LIN, COL);
    menorValorMatriz(m, LIN, COL);
    return 0;
}

void preencherMatriz(int m[][COL], int lin, int col) {
    for (int i = 0; i < lin; i += 1) {
        for (int j = 0; j < col; j += 1) {
            printf("Digite o valor de m[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &m[i][j]);
        }
    }
}

void preencherMatrizAleatorio(int m[][COL], int lin, int col) {
    for (int i = 0; i < lin; i += 1) {
        for (int j = 0; j < col; j += 1) {
            m[i][j] = rand() % 100 + 1;
        }
    }
}

void imprimirMatriz(int m[][COL], int lin, int col) {
    for (int i = 0; i < lin; i += 1) {
        for (int j = 0; j < col; j += 1) {
            printf("%3d\t", m[i][j]);
        }
        printf("\n");
    }
}

void menorValorMatriz(int m[][COL], int lin, int col){
    int menor_valor = 0, linha = 0, coluna = 0;
    for(int i = 0; i < lin; i+=1){
        for(int j = 0; j < col; j += 1){
            if((i == 0 && j == 0) || m[i][j] < menor_valor){
                menor_valor = m[i][j];
                linha = i;
                coluna = j;
            }
        }
    }
    printf("O menor valor é: %d\n", menor_valor);
    printf("A linha é: %d\n", linha + 1);
    printf("A coluna é: %d\n", coluna + 1);
}

void maiorValorMatriz(int m[][COL], int lin, int col){
    int maior_valor = 0, linha = 0, coluna = 0;
    for(int i = 0; i < lin; i+=1){
        for(int j = 0; j < col; j += 1){
            if((i == 0 && j == 0) || m[i][j] > maior_valor){
                maior_valor = m[i][j];
                linha = i;
                coluna = j;
            }
        }
    }
    printf("O maior valor é: %d\n", maior_valor);
    printf("Está na linha %d e colouna %d\n", linha + 1, coluna + 1);
}

