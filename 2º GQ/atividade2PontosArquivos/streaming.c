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
    int qtd_favoritos;
};

int buscarUsuarioEmail(char nomeArqUsuarios[], char email[]); 
int buscarUsuarioId(char nomeArqUsuarios[], int id);
void mostrarVideosFavoritos(struct Video vv[], int tam);
void cadastrarUsuario();
void mostrarVideos(char nomeArqVideos[]);
void lerStr(char str[], int tamMax);
int buscarVideo(char nomeArqVideos[], int id);
void mostrarUsuarios(char nomeArqUsuarios[]);
int qtdUsuariosCadastrados(char nomeArqUsuarios[]);
int qtdVideosCadastrados(char nomeArqVideos);
void adicionarVideoAosFavoritos(char nomeArqVideos[], char nomeArqUsuarios[]);
void atualizarUsuario(char nomeArqUsuarios[]);
void atualizarVideo(char nomeArqVideos);
void relatorio(char nomeArqVideos[], char nomeArqUsuarios[]);
void excluirUsuario(char nomeArquivoUsuarios[]);
void excluirVideo(char nomeArqVideos[]);

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
        printf("\n[8] Relatorio");
        printf("\n[9] Excluir Usuario");
        printf("\n[10] Excluir Video");
        printf("\n[11] Ver um video especifico");
        printf("\n[12] Ver um usuario especifico");
        printf("\n[0] Fechar programa\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                cadastrarUsuario(nomeArqUsuarios);
            case 2:
                cadastrarVideo(nomeArqVideos);
            case 3:
                mostrarVideos(nomeArqVideos);
            case 4:
                mostrarUsuarios(nomeArqUsuarios);
            case 5:
                adicionarVideoAosFavoritos(nomeArqVideos, nomeArqUsuarios);
            case 6:
                atualizarUsuario(nomeArqUsuarios);
            case 7:
                atualizarVideo(nomeArqVideos);
            case 8:
                relatorio(nomeArqVideos, nomeArqUsuarios);
            case 9:
                excluirUsuario(nomeArqUsuarios);
            case 10:
                excluirVideo(nomeArqVideos);
            case 11:

            case 12:
        }    
    }
    return 0;
}

void lerStr(char str[], int tamMax) {
    fgets(str, tamMax, stdin);
    int tam = strlen(str);
    if (tam > 0 && str[tam - 1] == '\n') {
        str[tam - 1] = '\0';
    }
}

void cadastrarUsuario(char nomeArqUsuarios[]){
    struct Usuario novo;
    char email[TAM_MAX_EMAIL];
    int resultadoBusca, id;

    if(qtdUsuariosCadastrados(nomeArqUsuarios) == MAX_USUARIOS){
        printf("Limite de usuarios cadastrados %d atingido.", MAX_USUARIOS);
        return;
    }

    printf("Digite o id do novo usuario: ");
    scanf("%d", &id);
    getchar();
    resultadoBusca = buscarUsuarioId(nomeArqUsuarios, id);
    if(resultadoBusca != -1){
        printf("Id ja cadastrado.");
        return;
    }
    novo.id = id;

    printf("\nDigite o email do usuário: ");
    lerStr(email, TAM_MAX_EMAIL);
    resultadoBusca = buscarUsuarioEmail(nomeArqUsuarios, email);
    if(resultadoBusca != -1){
        printf("Email ja cadastrado.");
        return;
    }
    strcpy(novo.email, email);

    printf("Digite o nome de usuário: ");
    lerStr(novo.nome, TAM_MAX_NOME);

    FILE * arq = fopen(nomeArqUsuarios, "ab");
    if(arq == NULL){
        printf("Erro ao abrir arquivo.");
        return;
    }

    fwrite(&novo, sizeof(struct Usuario), 1, arq);

    fclose(arq);

    printf("\nUsuario %s cadastrado com sucesso!", novo.nome);
}

int buscarUsuarioEmail(char nomeArqUsuarios[], char email[]){
    FILE * arq = fopen(nomeArqUsuarios, "rb");
    int i = 0;

    if (arq == NULL) {
        printf("Erro ao abrir arquivo de usuarios.");
        return 0; 
    }

    struct Usuario u;

    while(fread(&u, sizeof(struct Usuario), 1, arq) == 1){
        if(strcmp(u.email, email) == 0){
            fclose(arq);
            return i;
        }
        i+=1;
    }
    fclose(arq);
    return -1;
}

int buscarUsuarioId(char nomeArqUsuarios[], int id){
    FILE * arq = fopen(nomeArqUsuarios, "rb");
    int i = 0;

    if (arq == NULL) {
        printf("Erro ao abrir arquivo de usuarios.");
        return 0; 
    }

    struct Usuario u;

    while(fread(&u, sizeof(struct Usuario), 1, arq) == 1){
        if(u.id == id){
            fclose(arq);
            return i;
        }
        i+=1;
    }
    fclose(arq);
    return -1;
}

void cadastrarVideo(char nomeArqVideos[]){
    struct Video novo;
    char titulo[TAM_MAX_TITULO], descricao[TAM_MAX_DESCRICAO], tema[TAM_MAX_TEMA];
    int id, resultadoBusca;

    if(qtdVideosCadastrados(nomeArqVideos) == MAX_VIDEOS_CADASTRADOS){
        printf("Limite de videos cadastrados atingido (%d)", MAX_VIDEOS_CADASTRADOS);
        return;
    }

    printf("Digite o id do video: ");
    scanf("%d", &id);
    getchar();

    resultadoBusca = buscarVideo(nomeArqVideos, id);
    if(resultadoBusca == -1){
        printf("Id ja cadastrado.");
        return;
    }

    printf("Digite o titulo do video: ");
    lerStr(novo.titulo, TAM_MAX_TITULO);
    printf("Digite a descricao do video: ");
    lerStr(novo.descricao, TAM_MAX_DESCRICAO);
    printf("Digite o tema do video: ");
    lerStr(novo.tema, TAM_MAX_TEMA);

    FILE * arq = fopen(nomeArqVideos, "ab");

    if(arq == NULL){
        printf("Erro ao abrir arquivo de videos.");
        return;
    }
    fwrite(&novo, sizeof(struct Video), 1, arq);
    fclose(arq);

    printf("\nVideo cadastrado com sucesso.");
}

int buscarVideo(char nomeArqVideos[], int id){
    FILE * arq = fopen(nomeArqVideos, "rb");
    int i = 0;

    if (arq == NULL) {
        printf("Erro ao abrir arquivo de videos.");
        return 0; 
    }

    struct Video u;

    while(fread(&u, sizeof(struct Video), 1, arq) == 1){
        if(u.id == id){
            fclose(arq);
            return i;
        }
        i+=1;
    }
    fclose(arq);
    return -1;
}

void mostrarVideos(char nomeArqVideos[]){
    FILE * arq = fopen(nomeArqVideos, "rb");

    if (arq == NULL) {
        printf("Erro ao abrir arquivo de videos.");
        return; 
    }

    struct Video u;
    while(fread(&u, sizeof(struct Video), 1, arq) == 1){
        printf("\nId: %d\n", u.id);
        printf("Titulo: %s\n", u.titulo);
    }

    fclose(arq);
}

void mostrarUsuarios(char nomeArqUsuarios[]){
    FILE * arq = fopen(nomeArqUsuarios, "rb");

    if(arq == NULL){
        printf("Erro ao abrir arquivo de usuarios.");
        return;
    }

    struct Usuario u;

    while(fread(&u, sizeof(struct Usuario), 1, arq) == 1){
        printf("\nId: %d\n", u.id);
        printf("Nome: %s\n", u.nome);
    }

    fclose(arq);
}

void adicionarVideoAosFavoritos(char nomeArqVideos[], char nomeArqUsuarios[]){
    int idUsuario, idVideo, buscaUsuario;

    printf("Digite o ID do usuario que ira adicionar o video: ");
    scanf("%d", &idUsuario);

    buscaUsuario = buscarUsuarioId(nomeArqUsuarios, idUsuario);
    if(buscaUsuario == -1){
        printf("Usuario nao cadastrado.");
        return;
    }

    printf("Digite o id do video que deseja adicionar aos favoritos: ");
    scanf("%d", &idVideo);

    if(buscarVideo(nomeArqVideos, idVideo) == -1){
        printf("Video nao cadastrado.");
        return;
    }

    FILE * arq = fopen(nomeArqUsuarios, "r+b");

    if(arq == NULL){
        printf("Erro ao abrir arquivo de usuarios.");
        return;
    }

    struct Usuario u;

    long posicaoBytes = buscaUsuario * sizeof(struct Usuario);
    fseek(arq, posicaoBytes, SEEK_SET);

    fread(&u, sizeof(struct Usuario), 1, arq);

    if(u.qtd_favoritos == QTD_MAX_VIDEOS){
        printf("Limite de videos favoritos do usuario atingido.");
        fclose(arq);
        return;
    }

    u.idsVideosFavoritos[u.qtd_favoritos] = idVideo;
    u.qtd_favoritos += 1;

    fseek(arq, -sizeof(struct Usuario), SEEK_CUR);
    fwrite(&u, sizeof(struct Usuario), 1, arq);

    printf("Video adicionado aos favoritos com sucesso.");
    fclose(arq);
}

int qtdUsuariosCadastrados(char nomeArqUsuarios[]){
    FILE * arq = fopen(nomeArqUsuarios, "rb");

    if(arq == NULL){
        printf("Erro ao abrir arquivo de usuarios.");
        return 0;
    }

    fseek(arq, 0, SEEK_END);
    long tamanhoBytes = ftell(arq);

    fclose(arq);

    return tamanhoBytes / sizeof(struct Usuario);
}

int qtdVideosCadastrados(char nomeArqVideos){
    FILE * arq = fopen(nomeArqVideos, "rb");

    if(arq == NULL){
        printf("Erro ao abrir arquivo de videos.");
        return 0;
    }

    fseek(arq, 0, SEEK_END);
    long tamanhoBytes = ftell(arq);

    fclose(arq);

    return tamanhoBytes / sizeof(struct Video);
}

void atualizarUsuario(char nomeArqUsuarios[]){
    int idUsuario, buscaUsuario;

    printf("Digite o id do usuario que deseja atualizar: ");
    scanf("%d", &idUsuario);
    getchar();

    buscaUsuario = buscarUsuarioId(nomeArqUsuarios, idUsuario);

    if(buscaUsuario == -1){
        printf("Usuario nao cadastrado.");
        return;
    }

    FILE * arq = fopen(nomeArqUsuarios, "r+b");

    if(arq == NULL){
        printf("Erro ao abrir arquivo de usuarios.");
        return;
    }

    struct Usuario u;

    long posicaoBytes = buscaUsuario * sizeof(struct Usuario);
    fseek(arq, posicaoBytes, SEEK_SET);
    fread(&u, sizeof(struct Usuario), 1, arq);

    char temp[TAM_MAX_NOME];

    printf("Digite o novo nome do usuario (aperte enter se nao quer editar o nome): ");
    lerStr(temp, TAM_MAX_NOME);
    if(strlen(temp) > 0){
        strcpy(u.nome, temp);
    }
    printf("Digite o novo email do usuario (aperte enter se nao deseja editar o email): ");
    lerStr(temp, TAM_MAX_EMAIL);
    if(strlen(temp) > 0){
        strcpy(u.email, temp);
    }
    
    fseek(arq, -sizeof(struct Usuario), SEEK_CUR);
    fwrite(&u, sizeof(struct Usuario), 1, arq);

    printf("Usuario atualizado com sucesso.");
    fclose(arq);
}

void atualizarVideo(char nomeArqVideos){
    int idVideo, buscaVideo;

    printf("Digite o id do video que deseja atualizar: ");
    scanf("%d", &idVideo);
    getchar();

    buscarVideo(nomeArqVideos, idVideo);
    if(buscaVideo == -1){
        printf("Video nao cadastrado.");
        return;
    }

    FILE * arq = fopen(nomeArqVideos, "r+b");

    if(arq == NULL){
        printf("Erro ao abrir arquivo de usuarios.");
        return;
    }

    struct Video u;

    long posicaoBytes = buscaVideo * sizeof(struct Usuario);
    fseek(arq, posicaoBytes, SEEK_SET);
    fread(&u, sizeof(struct Usuario), 1, arq);

    char temp[TAM_MAX_TITULO];

    printf("Digite o novo titulo (aperte enter se nao quer editar o titulo): ");
    lerStr(temp, TAM_MAX_NOME);
    if(strlen(temp) > 0){
        strcpy(u.titulo, temp);
    }
    printf("Digite a nova descricao (aperte enter se nao deseja editar a descricao): ");
    lerStr(temp, TAM_MAX_DESCRICAO);
    if(strlen(temp) > 0){
        strcpy(u.descricao, temp);
    }
    printf("Digite o novo tema (aperte enter se nao deseja editar o tema): ");
    lerStr(temp, TAM_MAX_TEMA);
    if(strlen(temp) > 0){
        strcpy(u.tema, temp);
    }
    
    fseek(arq, -sizeof(struct Video), SEEK_CUR);
    fwrite(&u, sizeof(struct Video), 1, arq);

    printf("Video atualizado com sucesso.");
    fclose(arq);
}

void relatorio(char nomeArqVideos[], char nomeArqUsuarios[]){
    FILE * arqUsuarios = fopen(nomeArqUsuarios, "rb");
    FILE * arqVideos = fopen(nomeArqVideos, "rb");

    if(arqUsuarios == NULL){
        printf("Erro ao abrir arquivo de usuarios.");
        return;
    }
    if(arqVideos == NULL){
        printf("Erro ao abrir arquivo de videos.");
        return;
    }

    struct Usuario u;

    while(fread(&u, sizeof(struct Usuario), 1, arqUsuarios) == 1){
        printf("\nId: %d\n", u.id);
        printf("Nome: %s\n", u.nome);

        if (u.qtd_favoritos == 0) {
            printf("\t(Nenhum video favoritado)\n");
        }

        for(int i = 0; i < u.qtd_favoritos; i+=1){
            int buscaVideo;
            buscaVideo = buscarVideo(nomeArqVideos, u.idsVideosFavoritos[i]);

            if(buscaVideo == -1){
                printf("id %d nao encontrado.", u.idsVideosFavoritos[i]);
                continue;
            }
            struct Video v;
            long posicaoBytes = buscaVideo * sizeof(struct Video);
            fseek(arqVideos, posicaoBytes, SEEK_SET);
            fread(&v, sizeof(struct Video), 1, arqVideos);

            printf("Titulo: %s\n", v.titulo);
            printf("Descricao: %s\n", v.descricao);
            printf("Tema: %s\n", v.tema);
        }
    }

    fclose(arqUsuarios);
    fclose(arqVideos);
}

void excluirUsuario(char nomeArquivoUsuarios[]){
    int id;

    printf("Digite o id do usuario que deseja excluir: ");
    scanf("%d", &id);
    getchar();

    FILE * arqAntigo = fopen(nomeArquivoUsuarios, "rb");
    if(arqAntigo == NULL){
        printf("Erro ao abrir arquivo de usuarios.");
        return;
    }

    FILE *arqNovo = fopen("temp.bin", "wb");
    if (arqNovo == NULL) {
        printf("Erro ao criar arquivo temporario.\n");
        fclose(arqAntigo);
        return;
    }

    struct Usuario u;
    int encontrou = 0;

    while (fread(&u, sizeof(struct Usuario), 1, arqAntigo) == 1) {
        
        if (u.id == id) {
            encontrou = 1; 
        } else {
            fwrite(&u, sizeof(struct Usuario), 1, arqNovo);
        }
    }

    fclose(arqAntigo);
    fclose(arqNovo);

    if (encontrou == 1) {
        remove(nomeArquivoUsuarios);
        
        rename("temp.bin", nomeArquivoUsuarios);
        
        printf("Usuario excluido com sucesso!\n");
    } else {
        remove("temp.bin");
        printf("Erro: Usuario ID %d nao encontrado.\n", id);
    }
}

void excluirVideo(char nomeArqVideos[]){
    int id;

    printf("Digite o id do video que deseja excluir: ");
    scanf("%d", &id);
    getchar();

    FILE * arqAntigo = fopen(nomeArqVideos, "rb");
    if(arqAntigo == NULL){
        printf("Erro ao abrir arquivo de usuarios.");
        return;
    }

    FILE *arqNovo = fopen("temp.bin", "wb");
    if (arqNovo == NULL) {
        printf("Erro ao criar arquivo temporario.\n");
        fclose(arqAntigo);
        return;
    }

    struct Video u;
    int encontrou = 0;

    while (fread(&u, sizeof(struct Video), 1, arqAntigo) == 1) {
        
        if (u.id == id) {
            encontrou = 1; 
        } else {
            fwrite(&u, sizeof(struct Video), 1, arqNovo);
        }
    }

    fclose(arqAntigo);
    fclose(arqNovo);

    if (encontrou == 1) {
        remove(nomeArqVideos);
        
        rename("temp.bin", nomeArqVideos);
        
        printf("Video excluido com sucesso!\n");
    } else {
        remove("temp.bin");
        printf("Erro: Video ID %d nao encontrado.\n", id);
    }
}

void verUmVideo(char nomeArqVideos[]){
    int id, buscaVideo;

    printf("Digite o id do video que deseja ver: ");
    scanf("%d", &id);

    buscaVideo = buscarVideo(nomeArqVideos, id);

    if(buscaVideo == -1){
        printf("Video nao encontrado.");
        return;
    }

    FILE * arq = fopen(nomeArqVideos, "rb");

    if(arq == NULL){
        printf("Erro na abertura do arquivo de videos.");
        return;
    }

    struct Video v;
    long posicaoBytes = sizeof(struct Video) * buscaVideo;
    fseek(arq, posicaoBytes, SEEK_SET);
    fread(&v, sizeof(struct Video), 1, arq);

    printf("\nID: %d", v.id);
    printf("\nTitulo: %s", v.titulo);
    printf("\nDescricao: %s", v.descricao);
    printf("\nTema: %s", v.tema);

    fclose(arq);
}

void verUmUsuario(char nomeArqUsuarios[], char nomeArqVideos[]){
    int id, buscaUsuario;

    printf("Digite o id do usuario que deseja ver: ");
    scanf("%d", &id);

    buscaUsuario = buscarUsuarioId(nomeArqUsuarios, id);

    if(buscaUsuario == -1){
        printf("Usuario nao encontrado.");
        return;
    }

    FILE * arq = fopen(nomeArqUsuarios, "rb");

    struct Usuario u;
    long posicaoBytes = sizeof(struct Usuario) * buscaUsuario;
    fseek(arq, posicaoBytes, SEEK_SET);
    fread(&u, sizeof(struct Usuario), 1, arq);

    printf("\nID: %d", u.id);
    printf("\nNome: %s", u.nome);
    printf("\nEmail: %s", u.email);
    printf("\nVideos favoritos: ");
    if (u.qtd_favoritos == 0) {
            printf("\t(Nenhum video favoritado)\n");
            return;
        }
        
    FILE *arqVideos = fopen(nomeArqVideos, "rb");
    for(int i = 0; i < u.qtd_favoritos; i+=1){
        int buscaVideo;
        buscaVideo = buscarVideo(nomeArqVideos, u.idsVideosFavoritos[i]);

        if(buscaVideo == -1){
            printf("id %d nao encontrado.", u.idsVideosFavoritos[i]);
            continue;
        }
        
        struct Video v;
        long posicaoBytes = buscaVideo * sizeof(struct Video);
        fseek(arqVideos, posicaoBytes, SEEK_SET);
        fread(&v, sizeof(struct Video), 1, arqVideos);

        printf("Titulo: %s\n", v.titulo);
        printf("Descricao: %s\n", v.descricao);
        printf("Tema: %s\n", v.tema);
    }
    fclose(arq);
    fclose(arqVideos);
}