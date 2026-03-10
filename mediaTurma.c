#include <stdio.h>

void digitarAsNotas(double nota1[], double nota2[], int n);
void calcularMediaPorAluno(double nota1[], double nota2[], double media[], int n);
double calcularMediaDaTurma(double media[], int n);

int main(){

    double nota1[30] = {0}, nota2[30] = {0}, media[30] = {0}, media_total = 0;
     
    digitarAsNotas(nota1, nota2, 30);
    calcularMediaPorAluno(nota1, nota2, media, 30);
    media_total = calcularMediaDaTurma(media, 30);
    printf("A média da turma foi de: %.2lf \n", media_total);

    for(int i = 0; i < 30; i += 1){
        if(media[i] > media_total){
            printf("O %dº aluno teve média: %.2lf \n", i + 1, media[i]);
            printf("Com a nota 1 sendo %.2lf e a nota 2 sendo %.2lf \n", nota1[i], nota2[i]);
        }
    }

    return 0;
}

void digitarAsNotas(double nota1[], double nota2[], int n){
    double nota = 0;
    for(int i = 0; i < n; i += 1){
        printf("Digite a 1º nota do %dº aluno: ", i + 1);
        scanf("%lf", &nota);
        nota1[i] = nota;
        printf("Digite a 2º nota do %dº aluno: ", i + 1);
        scanf("%lf", &nota);
        nota2[i] = nota;
    }

    
    
}

void calcularMediaPorAluno(double nota1[], double nota2 [], double media[], int n){
    for(int i = 0; i < n; i += 1){
        double media_atual = ((double) nota1[i]*2 + (double) nota2[i] * 3) / 5;
        media[i] = media_atual;
    }
}

double calcularMediaDaTurma(double media[], int n){
    double soma = 0;
    double media_total = 0;

    for(int i = 0; i < n; i += 1){
        soma += media[i];
    }

    media_total = soma / n;
    return media_total;
}