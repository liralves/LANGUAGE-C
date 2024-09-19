#include <stdio.h>
#define TAM 5

void inserirElemento(int[], int*);
void imprimirVetor(int[], int);

int main(){
    
    int vector[TAM], tam = 0, opt = 0; 

    do{
        printf("MENU - Escolha as opções abaixo.\n");
        printf("1 - Inserir elemento no vetor.\n");
        printf("2 - Imprimir vetor.\n");
        printf("0 - Encerrar programa.\n");
        scanf("%d", &opt);

        switch (opt){
            case 1: inserirElemento(vector, &tam); break;
            case 2: imprimirVetor(vector, tam); break;
            default: if(opt == 0){
                break;
            }
        }
        


    }while(opt != 0);

}

void inserirElemento(int v[], int *tam){
    int n;
    if(*tam < TAM){
        printf("Insira um elemento:\n");
        scanf("%d", &v[*tam]);
        int i = *tam;
        while(i > 0 && v[i - 1] > n){
            v[i] = v[i - 1];
            i--;
        }
        *tam += 1;
        v[i] = n;

    }else {
        printf("\nVetor cheio.");
    }
}

void imprimirVetor(int v[], int tam){
    for(int i = 0; i < tam; i++){
        printf("%d", v[i]);
    }
    printf("\n");
}