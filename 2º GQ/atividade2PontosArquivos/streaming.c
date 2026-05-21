#include <stdio.h>
#include <string.h>

#define TAM_MAX_TEMA 20
#define TAM_MAX_TITULO 50
#define TAM_MAX_DESCRICAO 100
#define QTD_MAX_VIDEOS 50
#define TAM_MAX_NOME 20
#define TAM_MAX_EMAIL 40
#define MAX_USUARIOS 100
#define MAX_VIDEOS_CADASTRADOS 100

struct Video{
    int id;
    char titulo[TAM_MAX_TITULO];
    char tema[TAM_MAX_TEMA];
    char descricao[TAM_MAX_DESCRICAO];
};

struct Usuario{
    int id;
    char nome[TAM_MAX_NOME];
    char email[TAM_MAX_EMAIL];
    int idsVideosFavoritos[QTD_MAX_VIDEOS];
};

int buscarUsuario(struct Usuario vu[], int tam, char email[]); 
void mostrarVideosFavoritos(struct Video vv[], int tam);

int main(){
    FILE * arqVideosCadastrados;
    FILE * arqUsuariosCadastrados;
    char nomeArqVideos[] = "videosCadastrados.bin";
    char nomeArqUsuarios[] = "usuariosCadastrados.bin";

    int opcao = 1, status;

    //arqVideosCadastrados = fopen(nomeArqVideos, "wb"); Criação do arquivo de vídeos cadastrados
    //arqUsuariosCadastrados = fopen(nomeArqUsuarios, "wb");  Criação do arquivo de usuários cadastrados

    // arqVideosCadastrados = fopen(nomeArqVideos, "a+b");
    // arqUsuariosCadastrados = fopen(nomeArqUsuarios, "a+b"); 

    while(opcao != 0){
        printf("Olá! Bem vindo ao seu Streaming de vídeos. Escolha uma das opções abaixo: ");
        printf("\n[1] Cadastrar novo usuario");
        printf("\n[2] Cadastrar novo video");
        printf("\n[3] Ver todos os videos cadastrados");
        printf("\n[4] Vizualizar todos os usuários cadastrados");
        printf("\n[5] Adicionar video aos favoritos");
        printf("\n[6] Atualizar usuário");
        printf("\n[7] Atualizar video");
        printf("\n[0] Fechar programa\n");
        scanf("%d", &opcao);

        
    // }
    // return 0;
}

void cadastrarUsuario(){
    struct Usuario novo;
    char email[TAM_MAX_EMAIL];
    int resultadoBusca;

    printf("\nDigite o email do usuário: ");
    scanf(" %[^\n]", novo.email);
    resultadoBusca = buscarUsuario(email);
    if(resultadoBusca != -1){
        printf("Email já cadastrado.");
        return;
    }

    printf("Digite o nome de usuário: ");
    scanf(" %[^\n]", novo.nome);

    novo.idsVideosFavoritos = 0;

    FILE * arq = fopen("usuariosCadastrados.bin", "ab")
    

}

int buscarUsuario(char email[]){
    FILE * arq = fopen("usuariosCadastrados.bin", "rb");
    int i = 0;

    if (arq == NULL) {
        return 0; 
    }

    struct Usuario u;

    while(fread(&u, sizeof(Usuario), 1, arq) == 1){
        if(strcmp(u.email, email) == 0){
            fclose(arq);
            return i;
        }
        i+=1;
    }
    fclose(arq);
    return -1;
}

void mostrarVideos(struct Video vv[], int tam){

}