#include <stdio.h>

int main(){
    FILE * arq;
    char nomeArq[] = "teste.bin";
    int status;
    arq = fopen(nomeArq, "rb");
    if(!arq){
        printf("Erro na abertura do arquivo");
        return 1;
    }
    
    printf("Arquivo aberto com sucesso\n");



    status = fclose(arq);

    if(status == 1){
        printf("Erro ao tentar fechar arquivo %s\n", nomeArq);
        return 2;
    }
    printf("Arquivo %s fechado com sucesso\n", nomeArq);
    
    return 0;
}