#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 256

int main(){
    //at vai adicionar no fim do arquivo, criando um arquivo novo.
    FILE *arquivo = fopen("teste.txt", "at");
    char str[TAM];

    //retorno NULO quando não há a abertura do arquivo.
    if(arquivo == NULL){
        printf("Erro na abertura do arquivo.\n");
        return 1;
    }else{
        printf("Arquivo aberto.");
    }

    printf("");
    lerStr(str, TAM, stdin);


    return 0;
}

void lerStr(char *str, int TAM, FILE *arquivo){
    fgets(str, TAM, arquivo);
    int LEN = strlen(str);
    if(str[LEN - 1] == '\n'){
        str[LEN - 1] == '\0';
    }
}
