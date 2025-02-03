//imprimir um array percorrendo-o com uso de aritmetica de ponteiros
#include <stdio.h>
#define TAM 5

void imprimirArray(int array[], int size){
    
    int *p;
    for(p = array; p < &array[size]; ++p){
        printf("Elemento - [%d] ", *p);
    }
}

void preencherArray(int *arr, int size){
    
    for(int i = 0; i < size; ++i){
        scanf("%d", &arr[i]);
    }
}

int main(){
    
    int array[TAM];
    
    preencherArray(array, TAM);
    imprimirArray(array, TAM);
}