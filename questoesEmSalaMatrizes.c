#include <stdio.h>
#include <stdlib.h>

#define LIN 3
#define COL 3

void somarMatrizes(int matA[][COL], int matB[][COL], int matSoma[][COL], int lin, int col);
void preencherMatriz(int mat[][COL], int lin, int col);
void imprimirMatriz(int mat[][COL], int lin, int col);
void retornaTransposta(int matA[][COL], int lin, int col);


int main(){
    int matA[LIN][COL] = {0}, matB[LIN][COL] = {0}, matSoma[LIN][COL] = {0};
    srand(2);
    
    preencherMatriz(matA, LIN, COL);
    preencherMatriz(matB, LIN, COL);
    somarMatrizes(matA, matB, matSoma, LIN, COL);
    imprimirMatriz(matSoma, LIN, COL);
    
    printf("\n");
    imprimirMatriz(matA, LIN, COL);
    retornaTransposta(matA, LIN, COL);
    printf("\n");
    imprimirMatriz(matA, LIN, COL);

    return 0;
}

void somarMatrizes(int matA[][COL], int matB[][COL], int matSoma[][COL], int lin, int col){

    for(int i = 0; i < lin; i+=1){
        for(int j = 0; j < col; j += 1){
            matSoma[i][j] = matA[i][j] + matB[i][j];
        }
    }
}

void retornaTransposta(int matA[][COL], int lin, int col){
    if(lin != col){
        printf("Não é possível realizar a transposta");
    }else{
        int aux = 0;
        for(int i = 0; i < lin; i += 1){
            for(int j = 0; j < col; j += 1){
                if(j > i){
                    aux = matA[j][i];
                    matA[j][i] = matA[i][j];
                    matA[i][j] = aux;
                }
            }
        }
    }
}

void multiplicarMatrizes(int matA[][COL], 
    int matB[][COL], int matMult[][COL], 
    int linA, int colA, int linB, int colB){
    if(linA == colB){
        int resultado = 0, colMatMult = 0;
        for(int i = 0; i < linA; i += 1){
            for(int j = 0; j < colA; i += 1){
                resultado = matA[i][j] * matB[j][i];
                matMult[i][j] = resultado;
            }
            
        }
    }
}

void preencherMatriz(int mat[][COL], int lin, int col){
    for(int i = 0; i < lin; i += 1){
        for(int j = 0; j < col; j+=1){
            mat[i][j] = rand() % 11;
        }
    }
}

void imprimirMatriz(int mat[][COL], int lin, int col){
    for(int i = 0; i < lin; i += 1){
        for(int j = 0; j < col; j += 1){
            printf("%d \t", mat[i][j]);
        }
        printf("\n");
    }
}