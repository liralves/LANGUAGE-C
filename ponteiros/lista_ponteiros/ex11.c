#include <stdio.h>
#define TAM 5


void preencherArray(int arr[], int size){
    for(int i = 0; i < size; ++i){
        scanf("%d", &arr[i]);
    }
}

void exibirEndereco(int arr[], int size){
    
    for(int i = 0; i < size; i++){
        if(arr[i] % 2 == 0){ //faz printar apenas os elementos, seus indices e endereços respectivos aos elementos pares
            printf("Elemento = %d - Indice = %d - Endereço: %p\n", arr[i], (i + 1), &arr[i]);
        }
    }
}

int main()
{
    
    int array[TAM];
    preencherArray(array, TAM);
    exibirEndereco(array, TAM);
    

    return 0;
}