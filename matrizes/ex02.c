#include <stdio.h>
#define lin 10
#define col 10
void searchNumber(int[lin][col], int, int, int);
void ordemMatrix(int*, int*);
void fillMatrix(int[lin][col], int*, int*);
int sumMatrix(int[lin][col], int, int);

int main(){

    int matrix[lin][col], l = 0, c = 0, k = 0, sum = 0;

    ordemMatrix(&l, &c);
    fillMatrix(matrix, &l, &c);

    printf("Digite o valor a ser procurado na matriz:\n");
    scanf("%d", &k);

    searchNumber(matrix, l, c, k);

    sum = sumMatrix(matrix, l, c);
    printf("O somatório de todos os elementos da matriz é: %d\n", sum);


}

void searchNumber(int matrix[lin][col], int l, int c, int k){
    int f = 0;

    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            if(matrix[i][j] == k){
                printf("Valor %d encontrado na posição [%d][%d]\n", k, i, j);
                f = 1;       
            }
        }
    }
}

void ordemMatrix(int *l, int *c){
    printf("Quantidade de LINHAS:\n");
    scanf("%d", l);
    printf("Quantidade de COLUNAS:\n");
    scanf("%d", c);
}

void fillMatrix(int matrix[lin][col], int *l, int *c){
    for(int i = 0; i < *l; i++){
        for(int j = 0; j < *c; j++){
            printf("[%d][%d] = \n", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

int sumMatrix(int matrix[lin][col], int l, int c) {
    int soma = 0;

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            soma += matrix[i][j];
        }
    }

    return soma;
}