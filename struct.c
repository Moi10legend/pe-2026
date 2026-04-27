#include <stdio.h>

#define TAM_TURMA 30

struct Aluno{
    double nota1;
    double nota2;
    double media;
};

void imprimirNotasEMediasAcimaDaGeral(struct Aluno turma[], double mediaTurma);
double calcularMediaTurma(struct Aluno turma[]);
void preencherTurma(struct Aluno turma[]);

int main(){
    struct Aluno turma[TAM_TURMA];
    double mediaTurma = 0;
    preencherTurma(turma);
    mediaTurma = calcularMediaTurma(turma);
    imprimirNotasEMediasAcimaDaGeral(turma, mediaTurma);

    return 0;
}

void preencherTurma(struct Aluno turma[]){
    for(int i = 0; i < TAM_TURMA; i+=1){
        printf("Informe a primeira nota do %dº aluno: ", i+1);
        scanf("%lf",&turma[i].nota1);
        printf("Informe a segunda nota do %dº aluno: ", i+1);
        scanf("%lf",&turma[i].nota2);
        turma[i].media = (2*turma[i].nota1 + 3*turma[i].nota2) / 5;
    }
}

double calcularMediaTurma(struct Aluno turma[]){
    double somaMedia = 0, mediaTurma = 0;
    for(int i = 0; i < TAM_TURMA; i+=1){
        somaMedia += turma[i].media;
    }
    mediaTurma = somaMedia / TAM_TURMA;
    printf("A media da turma é: %.2lf\n", mediaTurma);

    return mediaTurma;
}

void imprimirNotasEMediasAcimaDaGeral(struct Aluno turma[], double mediaTurma){
    for(int i = 0; i < TAM_TURMA; i+=1){
        if(turma[i].media > mediaTurma){
            printf("%dº Aluno nota1: %.2lf\n", i+1, turma[i].nota1);
            printf("%dº Aluno nota2: %.2lf\n", i+1, turma[i].nota2);
            printf("%dº Aluno media: %.2lf\n", i+1, turma[i].media);
        }
    }
}