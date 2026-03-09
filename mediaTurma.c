#include <stdio.h>

void digitarAsNotas(int nota1[], int nota2[], int n);
void calcularMediaPorAluno(int nota1[], int nota2[], double media[], int n);

int main(){

    int nota1[] = {30}, nota2[30] = {0};
    double media[30] = {};
    digitarAsNotas(nota1, nota2, 30);
    calcularMedia(nota1, nota2, media, 30);


    return 0;
}

void digitarAsNotas(int nota1[], int nota2[], int n){
    int nota = 0;
    for(int i = 0; i < n; i += 1){
        printf("Digite a 1º nota do %d aluno: ", i);
        scanf("%d", &nota);

        nota1[i] = nota;
    }

    for (int i = 0; i <  n; i += 1)
    {
        printf("Digite a 2º nota do %d aluno: ", i);
        scanf("%d", &nota);

        nota2[i] = nota;
    }
    
}

void calcularMediaPorAluno(int nota1[], int nota2 [], double media[], int n){
    for(int i = 0; i < n; i += 1){
        double media_atual = ((double) nota1[i]*2 + (double) nota2[i] * 3) / 5;
        media[i] = media_atual;
    }
}

double calcularMediadaTurma(double media[], int n){
    double soma = 0;
    double media_total = 0

    for(int i = 0; i < n, i += 1){

    }
}