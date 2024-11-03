#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TEMP_MAX 300000
#define TAM 3

void bubbleSort(int arr[], int n);
void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);

void fillArray(int arr[], int n, int type);
void print(char *algorithm, int size, int orderType, double tempoExecucao);

int main() {
    int sizes[] = {10, 100, 1000, 10000, 100000, 1000000, 10000000};
    int *arr;
    clock_t inicio, fim;
    double tempoExecucao;

    for (int i = 0; i < TAM; i++) {
        for (int tipo = 0; tipo < TAM; tipo++) {
            for (int k = 0; k < sizeof(sizes) / sizeof(sizes[0]); k++) {
                int LEN = sizes[k];
                arr = (int *) malloc(LEN * sizeof(int));
                
                if (arr == NULL) {
                    printf("Falha na alocação de memória!\n");
                    return 1;
                }
                
                fillArray(arr, LEN, tipo); 
                
                inicio = clock();
                if (i == 0) {
                    bubbleSort(arr, LEN);
                } else if (i == 1) {
                    insertionSort(arr, LEN);
                } else {
                    selectionSort(arr, LEN);
                }
                fim = clock();
                
                tempoExecucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC * 1000;
                
                if(tempoExecucao < TEMP_MAX){
                    arr[i] = (LEN / 2);
                }
                
                
                if (i == 0) {
                    print("BubbleSort", LEN, tipo, tempoExecucao);
                } else if (i == 1) {
                    print("InsertionSort", LEN, tipo, tempoExecucao);
                } else {
                    print("SelectionSort", LEN, tipo, tempoExecucao);
                }

                free(arr);
            }
        }
    }

    return 0;
}
void bubbleSort(int *arr, int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                int aux = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = aux;
            }
        }
    }
} 
void insertionSort(int arr[], int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void selectionSort(int *arr, int n) {	
	for (int i = 0; i < n; i++){
		
		int i_menor = i;
		for (int j = i + 1; j < n; j++)
			if (arr[j] < arr[i_menor])
				i_menor = j;
		
		int aux = arr[i];
		arr[i] = arr[i_menor];
		arr[i_menor] = aux;
	
	}		
}
void fillArray(int arr[], int n, int type) {
    int i;
    if (type == 0) { 
        for (i = 0; i < n; i++) {
            arr[i] = rand() % n;
        }
    } else if (type == 1) {
        for (i = 0; i < n; i++) {
            arr[i] = i;
        }
    } else {
        for (i = 0; i < n; i++) {
            arr[i] = n - i;
        }
    }
}
void print(char *algorithm, int size, int orderType, double tempoExecucao) {
    char *order;
    if (orderType == 0) {
        order = "Desordenado";
    } else if (orderType == 1) {
        order = "Ordenado Crescente";
    } else {
        order = "Ordenado Decrescente";
    }
    
    printf("Algoritmo: %s, Tamanho: %d, Ordem: %s, Tempo: %.3f ms\n", algorithm, size, order, tempoExecucao);
}