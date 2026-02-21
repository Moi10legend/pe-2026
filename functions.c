#include <stdio.h>

double calcularIMC(double peso, double altura);

int main(){
    double peso, altura, imc;
    printf("Digite a sua altura: ");
    scanf("%lf", &altura);

    printf("Digite o seu peso: ");
    scanf("%lf", &peso);

    printf("O seu IMC é de: %.2lf", calcularIMC(peso, altura));


    return 0;
}

double calcularIMC(double peso, double altura){
    return peso / (altura * altura);
}