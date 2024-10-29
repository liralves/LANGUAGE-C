#include <stdio.h>
#include <string.h>
 
#define MAX_PRODUTOS 4
#define TAM_DESCRICAO 200
#define TAM_CODIGO 10
 
typedef struct{
    char codigo[TAM_CODIGO], descricao[TAM_DESCRICAO];
    float valor;
    int quantidade;
}PRODUTO;
 
void receberString(char string[], int tam);
void limparBuffer();
void cadastrarProduto(PRODUTO estoque[], int* size);
void alterarValor(PRODUTO estoque[], char codigo[], int *size);
float getValor(PRODUTO estoque[], char codigo[], int *size);
int getQuantidade(PRODUTO estoque[], char codigo[], int *size);
void venda(PRODUTO estoque[], char codigo[], int quantidade, int* size);
void alterarQuantidade(PRODUTO estoque[], char codigo[], int *size);
void exibirProdutos(PRODUTO estoque[], int *size);
void produtosZerados(PRODUTO estoque[], int *size);
 
int main(){
    PRODUTO estoque[MAX_PRODUTOS];
    int size = 0, op, quantidade;
    char codigo[TAM_CODIGO];
    float valor;    
    do{
        printf("\n1 - Cadastre o produto desejado:\n");
        printf("2 - Alterar valor de unitário do produto:\n");
        printf("3 - Verificar valor unitário do produto:\n");
        printf("4 - Informar quantidade do produto no estoque:\n");
        printf("5 - Comprar produto:\n");
        printf("6 - Atualizar quantidade do estoque.\n");
        printf("7 - Exibir codigo e descricao dos produtos.\n");
        printf("8 - Exibir codigo e descricao dos produtos com estoque zero.\n");
        scanf("%d", &op);
        limparBuffer();
        switch(op){
            case 1:
            cadastrarProduto(estoque, &size);
            break;
            case 2:
            printf("Digite o código do produto que deseja alterar o valor:\n");
 
            receberString(codigo, TAM_CODIGO);
            alterarValor(estoque, codigo, &size);
            break;
            case 3:
            printf("Digite o código do produto que deseja consultar o valor:\n");
            receberString(codigo, TAM_CODIGO);
            valor = getValor(estoque, codigo, &size);
            printf("\nO valor unitário do produto é: %.2f\n", valor);
            break;
            case 4:
            printf("Digite o código do produto que deseja consultar a quantidade:\n");
            receberString(codigo, TAM_CODIGO);
            quantidade = getQuantidade(estoque, codigo, &size);
            printf("\nA quantidade do produto no estoque é: %d\n", quantidade);
            break;
            case 5:
            printf("Digite o código do produto que deseja comprar:\n");
            receberString(codigo, TAM_CODIGO);
            printf("Digite a quantidade desejada do produto:\n");
            scanf("%d", &quantidade);
            venda(estoque, codigo, quantidade, &size);
            break;
            case 6:
            printf("Digite o código do produto que deseja comprar:\n");
            receberString(codigo, TAM_CODIGO);
            alterarQuantidade(estoque,codigo, &size);
            break;
            case 7:
            exibirProdutos(estoque, &size);
            break;
            case 8:
            produtosZerados(estoque,&size);
            break;
            case 0:
            break;
            default:
            printf("opção invalida.");
            break;
        }
    }while(op != 0);


 
    return 0;
}
 
void cadastrarProduto(PRODUTO estoque[], int* size){
    if(*size < MAX_PRODUTOS-1){
        printf("\nDigite o código do produto: ");
        receberString(estoque[*size].codigo, TAM_CODIGO);
        printf("\nDigite a descrição do produto: ");
        receberString(estoque[*size].descricao, TAM_DESCRICAO);    
        printf("\nDigite o unitário do produto: ");
        scanf("%f", &estoque[*size].valor);
        printf("\nDigite a quantidade do produto no estoque: ");
        scanf("%d", &estoque[*size].quantidade);
        (*size)++;
    }else{
        printf("Estoque cheio! Não é possivel cadastrar mais produtos!");
    }
}
 
void alterarValor(PRODUTO estoque[], char codigo[], int *size){
    int invalido = 1;
    for(int i = 0; i < (*size); i++){
        if(strcmp(codigo, estoque[i].codigo)==0){
            printf("\nO valor unitário atual do produto é %.2f.\nDigite o novo valor do produto:\n", estoque[i].valor);
            scanf("%f", &estoque[i].valor);
            invalido = 0;
        }
    }
    if(invalido){
        printf("Código inválido.");
    }
}
 
float getValor(PRODUTO estoque[], char codigo[], int *size){
    for(int i=0; i < *size; i++){
        if (strcmp(codigo, estoque[i].codigo)==0){
            return estoque[i].valor;
        }
    }
    printf("Código inválido!!");
    return 0;
}
 
int getQuantidade(PRODUTO estoque[], char codigo[], int *size){
    for(int i=0; i < *size; i++){
        if (strcmp(codigo, estoque[i].codigo)==0){
            return estoque[i].quantidade;
        }
    }
    printf("Código inválido!!");
    return 0;
}
 
void venda(PRODUTO estoque[], char codigo[], int quantidade, int *size) {
    int op;
    for (int i = 0; i < *size; i++) {
        if (strcmp(codigo, estoque[i].codigo) == 0) {
            if (quantidade <= estoque[i].quantidade) {
                float preco = estoque[i].valor * quantidade;
                do {
                    printf("O valor final da sua compra foi %.2f.\nDeseja efetuar a compra? Escolha 1 para 'sim' e 0 para 'não'\n", preco);
                    scanf("%d", &op);
                } while (op != 1 && op != 0);
                if (!op) {
                    printf("Compra cancelada!");
                    return;
                }
                estoque[i].quantidade -= quantidade;
                return;
            } else if (estoque[i].quantidade == 0) {
                printf("Não possui o produto no estoque!\n");
                return;
            } else {
                printf("A quantidade desejada é superior à quantidade presente no estoque.\nAtualmente, existem %d exemplares do produto no estoque.\n", estoque[i].quantidade);
                float preco = estoque[i].valor * estoque[i].quantidade;
                do {
                    printf("O valor da compra com a quantidade atual é: %.2f.\nDeseja efetuar a compra com esta quantidade? Escolha 1 para 'sim' e 0 para 'não'\n", preco);
                    scanf("%d", &op);
                } while (op != 1 && op != 0);
                if (!op) {
                    printf("Compra cancelada!");
                    return;
                }
                estoque[i].quantidade = 0;
                return;
            }
        }
    }
    printf("Código inválido!!\n");
}
 
void alterarQuantidade(PRODUTO estoque[], char codigo[], int *size){
    int invalido = 1;
    for(int i = 0; i < (*size); i++){
        if(strcmp(codigo, estoque[i].codigo)==0){
            printf("\nA quantidade atual do produto no estoque é %d.\nDigite a nova quantidade do produto:\n", estoque[i].quantidade);
            scanf("%d", &estoque[i].quantidade);
            invalido = 0;
        }
    }
    if(invalido){
        printf("Código inválido.");
    }
}
 
void exibirProdutos(PRODUTO estoque[], int *size){
    for(int i=0;i<*size;i++){
        printf("\nCódigo do produto: %s\n", estoque[i].codigo);
        printf("descricao do produto: %s\n",estoque[i].descricao);
    }
}
 
void produtosZerados(PRODUTO estoque[], int *size){
    for(int i=0;i<*size;i++){
        if(estoque[i].quantidade==0);
        printf("\nCódigo do produto: %s\n", estoque[i].codigo);
        printf("descricao do produto: %s\n",estoque[i].descricao);
    }
}
 
void receberString(char string[], int tam) {
    int lastchar;
    fgets(string, tam, stdin);
    lastchar = strlen(string) - 1;
    if (string[lastchar] == '\n') {
        string[lastchar] = '\0';
    }
    limparBuffer();
}
 
void limparBuffer() {
    char c;
    c = getchar();
    while (c != '\n' && c != EOF) {
        c = getchar();
    }
}