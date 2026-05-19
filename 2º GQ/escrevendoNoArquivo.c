#include <stdio.h>

int main(){
    FILE * arq;
    char nomeArq[] = "teste.bin";
    int status, num = 50;
    arq = fopen(nomeArq, "a+b");

    if(!arq){
        printf("Erro na abertura do arquivo %s\n", nomeArq);
        return 1;
    }
    printf("Sucesso na abertura do arquivo %s\n", nomeArq);
    
    while(fread(&num, sizeof(int),1, arq) == 1){
        printf("Número lido: %d\n", num);
    }

    status = fwrite(&num, sizeof(int), 1, arq);
    
    if(status == 0){
        printf("Erro na gravação do registro no arquivo\n");
    }else{
        printf("Registro gravado com sucesso: %d\n", num);
    }

    status = fclose(arq);

    if(status == 1){
        printf("Erro de fechamento do arquivo %s", nomeArq);
        return 2;
    }

    printf("Sucesso no fechamento do arquivo %s", nomeArq);
   
    return 0;
}