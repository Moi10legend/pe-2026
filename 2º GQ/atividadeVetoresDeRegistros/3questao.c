#include <stdio.h>

#define TAM_MAX_NOME 30
#define TAM_CPF 14
#define TAM_CADASTRO 100
#define TAM_TELEFONE 20

struct Conta{
    int numConta;
    char nome[TAM_MAX_NOME];
    char cpf[TAM_CPF];
    char telefone[TAM_TELEFONE];
    double saldo;
};

int buscarConta(struct Conta vc[], int totalContas, int numConta);
void preencherContaNova(struct Conta *conta, int numConta);
void cadastrarContaNova(struct Conta vc[], int tam, int *totalContas, int numConta);
void consultarSaldo(struct Conta vc[], int totalContas, int numConta);
void depositar(struct Conta vc[], int totalContas, int numConta);
void saque(struct Conta vc[], int totalContas, int numConta);
void exibirContas(struct Conta vc[], int totalContas);

int main(){
    struct Conta contasCorrente[TAM_CADASTRO], contasPoupança[TAM_CADASTRO];
    int totalContasCorrente = 0, totalContasPoupanca = 0;
    int contaBuscada;

    cadastrarContaNova(contasCorrente, TAM_CADASTRO, &totalContasCorrente, 1);
    contaBuscada = buscarConta(contasCorrente, totalContasCorrente, 1);
    printf("\nConta numero %d do usuário %s telefone %s\n", 
        contasCorrente[contaBuscada].numConta, 
        contasCorrente[contaBuscada].nome, 
        contasCorrente[contaBuscada].telefone);

    consultarSaldo(contasCorrente, totalContasCorrente, 1);

    depositar(contasCorrente, totalContasCorrente, 1);
    consultarSaldo(contasCorrente, totalContasCorrente, 1);
    saque(contasCorrente, totalContasCorrente, 1);
    consultarSaldo(contasCorrente, totalContasCorrente, 1);
    exibirContas(contasCorrente, totalContasCorrente);
    return 0;
}

int buscarConta(struct Conta vc[], int totalContas, int numConta){

    if(totalContas == 0){
        return -1;
    }

    for(int i = 0; i < totalContas; i+=1){
        if(vc[i].numConta == numConta){
            return i;
        }
    }

    return -2;
}

void preencherContaNova(struct Conta *conta, int numConta){
    conta->numConta = numConta;
    conta->saldo = 0.0;
    printf("Digite o nome do usuario da conta: ");
    scanf(" %[^\n]", conta->nome);
    printf("Digite o CPF do usuário (Formato: xxx.xxx.xxx-xx): ");
    scanf(" %[^\n]", conta->cpf);
    printf("\nDigite o telefone do usuário da conta (Apenas números): ");
    scanf(" %[^\n]", conta->telefone);
}

void cadastrarContaNova(struct Conta vc[], int tam, int *totalContas, int numConta){
    if (*totalContas >= tam) {
        printf("Erro: O cadastro de contas está cheio!\n");
        return;
    }

    if(buscarConta(vc, *totalContas, numConta) >= 0){
        printf("Não poderá fazer o cadastramento, pois se trata de um número de conta repetido.");
        return;
    }
    preencherContaNova(&vc[*totalContas], numConta);
    *totalContas += 1;
}

void consultarSaldo(struct Conta vc[], int totalContas, int numConta){
    int contaBuscada;
    contaBuscada = buscarConta(vc, totalContas, numConta);
    if(contaBuscada < 0){
        printf("\nConta não existente.\n");
        return;
    }

    printf("\nO saldo da conta numero %d é de %.2lf\n", vc[contaBuscada].numConta, vc[contaBuscada].saldo);
}

void depositar(struct Conta vc[], int totalContas, int numConta){
    int contaBuscada;
    double valorDeposito;
    contaBuscada = buscarConta(vc, totalContas, numConta);

    if(contaBuscada < 0){
        printf("\nConta inexistente.\n");
        return;
    }

    printf("Digite o valor que deseja depositar: ");
    scanf("%lf", &valorDeposito);
    vc[contaBuscada].saldo += valorDeposito;
}

void saque(struct Conta vc[], int totalContas, int numConta){
    int contaBuscada;
    double valorSaque;

    contaBuscada = buscarConta(vc, totalContas, numConta);

    if(contaBuscada < 0){
        printf("\nConta inexistente.\n");
        return;
    }

    printf("\nDigite o valor do saque: ");
    scanf("%lf", &valorSaque);

    if(valorSaque > vc[contaBuscada].saldo){
        printf("\nO valor é maior que o disponível em saldo.\n");
        return;
    }

    vc[contaBuscada].saldo -= valorSaque;
}

void exibirContas(struct Conta vc[], int totalContas){
    for(int i = 0; i < totalContas; i += 1){
        printf("\n---Conta %d---\n", i + 1);
        printf("Numero da conta: %d\n", vc[i].numConta);
        printf("Nome do titular: %s\n", vc[i].nome);
        printf("Telefone do titular: %s\n", vc[i].telefone);
    }
}