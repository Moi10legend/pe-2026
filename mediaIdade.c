#include <stdio.h>
int main(){
	int idade, qtdPessoas = 0, soma = 0;
	double media;
	printf("Digite a sua idade: ");
	scanf("%d", &idade);
	
	while(idade >= 0){
		qtdPessoas += 1;
		soma += idade;
		printf("Digite a sua idade: ");
		scanf("%d", &idade);
	}
	
	media = (double) soma / qtdPessoas;
	printf("A media e de: %.2lf", media);
	
}