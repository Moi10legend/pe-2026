#include <stdio.h>

void preecherVetor(int v[], int numeroDeElementos);
void imprimirValores(int v[], int tam);

int main(){
    int numeros[100] = {0}, tam = 5;
    
    preecherVetor(numeros, tam);
    for(int i = 0; i < tam; i += 1){
        printf("%d \n", numeros[i]);
    }

    imprimirValores(numeros, tam);
    return 0;
}

void preecherVetor(int v[], int numeroDeElementos){
    
    for(int i = 0; i < numeroDeElementos; i += 1){
        int num = 0;
        printf("Digite o %dº número inteiro: ", i + 1);
        scanf("%d", &num);
        v[i] = num;
    }
}

void imprimirValores(int v[], int tam){
    printf("{");

    for(int i = 0; i < tam; i += 1){
        printf("%d", v[i]);
        if(i < tam - 1){
            printf(", ");
        }
    }

    printf("}\n");
}

void ordenar(int v[], int n){
    int i, j, temp;

    for(i = 0; i < n - 1; i += 1){
        for (j = 0; j < n - i - 1; j++) {
            
            // Se o elemento da esquerda for maior que o da direita, eles trocam
            if (v[j] > v[j + 1]) {
                // A variável 'temp' ajuda a não perdermos o valor durante a troca
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
    
}
