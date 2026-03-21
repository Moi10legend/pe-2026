#include <stdio.h>

#define MAX_QTD 50

void insercaoOrdenada(int v[], int n);
void captarValores(int v[], int n);
void imprimirValores(int v[], int n);
int buscaBinaria(int v[], int n, int chave);
void removerElemento(int v[], int *n, int numero);
void inserirValor(int v[], int *n, int numero, int MAXQTD);

int main(){
    int tamanhoVetor = 0, numeros[MAX_QTD], escolha, chave, busca = 0;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanhoVetor);

    captarValores(numeros, tamanhoVetor);

    do{
        printf("\n[1] Imprimir todo o vetor \n");
        printf("[2] Consultar número\n");
        printf("[3] Remover um elemento\n");
        printf("[4] Adicionar um elemento\n");
        printf("[0] Finalizar programa\n");
        scanf("%d", &escolha);

        if(escolha == 1){
            imprimirValores(numeros, tamanhoVetor);
        }else if(escolha == 2){
            printf("Digite o número que deseja procurar: ");
            scanf("%d", &chave);
            busca = buscaBinaria(numeros, tamanhoVetor, chave);
            if(busca == -2){
                printf("O vetor está vazio");
            }else if(busca == -1){
                printf("O vetor não possui o número %d", chave);
            }else{
                printf("O número existe e está no index %d", busca);
            }
        }else if(escolha == 3){
            printf("Digite o número que deseja remover: ");
            scanf("%d", &chave);
            removerElemento(numeros, &tamanhoVetor, chave);
        }else if(escolha == 4){
            printf("Digite o número que deseja adicionar: ");
            scanf("%d", &chave);
            inserirValor(numeros, &tamanhoVetor, chave, MAX_QTD);
        }
    }while(escolha != 0);

    return 0;
}

void insercaoOrdenada(int v[], int n){
    int i, j, key;

    for(i = 1; i < n; i +=1){

        key = v[i];
        j = i - 1;
        while(j >= 0 && v[j] > key){
            v[j + 1] = v[j];
            j = j - 1;
        }

        v[j + 1] = key;
    }
    
}

void captarValores(int v[], int n){
    int numeroDaVez = 0;
    for(int i = 0; i < n; i += 1){
         
        printf("Digite o %dº número: ", i + 1);
        scanf("%d", &numeroDaVez);
        v[i] = numeroDaVez;
        insercaoOrdenada(v, i + 1);
    }
}

void imprimirValores(int v[], int n){
    for(int i = 0; i < n; i += 1){
        printf("%d ", v[i]);
    }
}



int buscaBinaria(int v[], int n, int chave){
    int inicio = 0, meio, fim = n - 1;

    if(n == 0){
        return -2;
    }
    do{
        meio = (inicio + fim) / 2;
        if(v[meio] > chave){
            fim = meio - 1;
        }else if(v[meio] < chave){
            inicio = meio + 1;
        }
    }while(v[meio] != chave && inicio <= fim);
    if(v[meio] == chave){
        return meio;
    }else{
        return -1;
    }
}

void removerElemento(int v[], int *n, int numero){
    int index = buscaBinaria(v, *n, numero);

    if(index == -1){
        printf("Número não encontrado");
    }else if(index == -2){
        printf("O vetor está vazio");
    }
    else{
        for(int i = index; i < *n; i += 1){
            v[i] = v[i + 1];
        }
        *n -= 1;
        printf("Número removido com sucesso");
    }
}

void inserirValor(int v[], int *n, int numero, int MAXQTD){
    if(*n == MAX_QTD){
        printf("Não é possível inserir outro valor, pois a capacidade do vetor foi atingida.");
    }else{
        v[*n] = numero;
        *n += 1;
        insercaoOrdenada(v, *n);
        printf("Número inserido com sucesso.");
    }
}

// void buscaBinaria(int v[], int n){
//     int i = 0, achou = 0, meio = 0, numero = 0;
//     printf("Digite o número que deseja pesquisar: ");
//     scanf("%d", &numero);
    
//     meio = n / 2;
//     while(achou = 0){
//         if(v[meio] == numero){
//             achou == 1;
//             print("O número existe no vetor e está no index %d", meio);
//         }else{
//             if(v[meio] > numero){
//                 meio = meio ;
//             }
//         }
//     }
// }