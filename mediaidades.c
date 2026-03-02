#include <stdio.h>

int main() {
    int idade, qtdPessoas = 0, soma = 0, idades[1000] = {0}, maxQtd = 5;
    double media;
    printf("Digite sua idade: ");
    scanf("%d", &idade);
    for(int i = 1; i < maxQtd; i += 1) {
        qtdPessoas += 1;
        soma += idade;
        scanf("%d", &idade);
        idades[i] = idade;
    }
    
    media = (double) soma / (double) qtdPessoas;
    printf("A média de idade dos participantes é de %.2lf anos\n", media);
    for(int i = 1; i < maxQtd; i += 1){
    	if(idades[i] > media){
    		printf("%d \n", idades[i]);   
		}
	} 
    return 0;
}