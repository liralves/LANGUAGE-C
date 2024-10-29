#include <stdio.h>
#include <string.h>

typedef struct{
    char numeroConta[8], nome[200], cpf[11], telefone[11];
    float saldo;
} CADASTRO;

void receberString(char string[], int tam);
void limparBuffer();
int busca(CADASTRO contas[], char numeroConta[], int *size);
void cadastroConta(CADASTRO contas[], char numeroNovo[], int *size);
void consultarSaldo(CADASTRO contas[], char numeroConta[], int *size);
void depositar(CADASTRO contas[], char numeroConta[], int *size);
void sacar(CADASTRO contas[], char numeroConta[], int *size);
void exibirCadastro(CADASTRO contas[], int *size);

int main() {
    int size = 0, op;
    CADASTRO contas[10]; 

    do {
        printf("\n--- Menu ---\n");
        printf("1. Cadastrar conta\n");
        printf("2. Consultar saldo\n");
        printf("3. Depositar\n");
        printf("4. Sacar\n");
        printf("5. Exibir todos os cadastros\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &op);
        limparBuffer();

        char numeroConta[8];
        
        switch (op) {
            case 1:
                printf("Digite o número da nova conta: ");
                receberString(numeroConta, 8);
                cadastroConta(contas, numeroConta, &size);
                break;
            case 2:
                printf("Digite o número da conta para consultar saldo: ");
                receberString(numeroConta, 8);
                consultarSaldo(contas, numeroConta, &size);
                break;
            case 3:
                printf("Digite o número da conta para depósito: ");
                receberString(numeroConta, 8);
                depositar(contas, numeroConta, &size);
                break;
            case 4:
                printf("Digite o número da conta para saque: ");
                receberString(numeroConta, 8);
                sacar(contas, numeroConta, &size);
                break;
            case 5:
                exibirCadastro(contas, &size);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (op != 0);

    return 0;
}

int busca(CADASTRO contas[], char numeroConta[], int *size) {
    if (*size == 0) return -1;
    for (int i = 0; i < *size; i++) {
        if (strcmp(contas[i].numeroConta, numeroConta) == 0) {
            return i;
        }
    }
    return -2;
}

void cadastroConta(CADASTRO contas[], char numeroNovo[], int *size) {
    int resultado = busca(contas, numeroNovo, size);
    if (resultado >= 0) {
        printf("O número da conta é repetido. Cadastro inválido.\n");
    } else {
        strcpy(contas[*size].numeroConta, numeroNovo);
        printf("Digite o seu nome completo:\n");
        receberString(contas[*size].nome, 200);
        printf("Digite o seu CPF:\n");    
        receberString(contas[*size].cpf, 11);
        printf("Digite o seu telefone:\n");
        receberString(contas[*size].telefone, 11);
        contas[*size].saldo = 0;
        (*size)++;
    }
}

void consultarSaldo(CADASTRO contas[], char numeroConta[], int *size) {
    int resultado = busca(contas, numeroConta, size);
    if (resultado >= 0) {
        printf("O saldo na conta é: %.2f\n", contas[resultado].saldo);
    } else {
        printf("Não existe uma conta cadastrada com este número de conta.\n");
    }
}

void depositar(CADASTRO contas[], char numeroConta[], int *size) {
    int resultado = busca(contas, numeroConta, size);
    if (resultado >= 0) {
        float deposito;
        printf("Digite o valor do depósito: ");
        scanf("%f", &deposito);
        limparBuffer();
        contas[resultado].saldo += deposito;
        printf("Depósito realizado com sucesso!\n");
    } else {
        printf("Não existe uma conta cadastrada com este número de conta.\n");
    }
}

void sacar(CADASTRO contas[], char numeroConta[], int *size) {
    int resultado = busca(contas, numeroConta, size);
    if (resultado >= 0) {
        float saque;
        printf("Digite o valor a ser sacado: ");
        scanf("%f", &saque);
        limparBuffer();
        if (contas[resultado].saldo >= saque) {
            contas[resultado].saldo -= saque;
            printf("Saque realizado com sucesso!\n");
        } else {
            printf("Saldo insuficiente para realizar o saque.\n");
        }
    } else {
        printf("Não existe uma conta cadastrada com este número de conta.\n");
    }
}

void exibirCadastro(CADASTRO contas[], int *size) {
    for (int i = 0; i < *size; i++) {
        printf("\nNúmero da conta: %s\n", contas[i].numeroConta);
        printf("Nome do titular: %s\n", contas[i].nome);
        printf("Telefone para contato: %s\n", contas[i].telefone);
        printf("CPF: %s\n", contas[i].cpf);
        printf("Saldo: %.2f\n", contas[i].saldo);
    }
}

void receberString(char string[], int tam) {
    fgets(string, tam, stdin);
    size_t len = strlen(string);
    if (len > 0 && string[len - 1] == '\n') {
        string[len - 1] = '\0';
    }
    limparBuffer();
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}