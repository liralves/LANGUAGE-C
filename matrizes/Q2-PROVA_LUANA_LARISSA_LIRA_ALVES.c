//APRENDIZ: LUANA LARISSA DE LIRA ALVES (INDIVIDUAL)
//RA: 00000851066

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define M 30
#define N 20


void fillMatrix(int m[M][N], int l, int c);
void printMatrix(int m[M][N], int l, int c);
void biggestVector(int m[M][N], int l, int c, int v[]);
void printVector(int v[], int size);
int repeatNumbers(int m[M][N], int l, int c, int *linha, int *coluna);
 
int main() {
    int matrix[M][N], vector[N];
    int option, linha, coluna, a;
 
    do {
        printf("\n1 - Preencher matriz.\n");
        printf("2 - Vetor com maiores.\n");
        printf("3 - Numeros repetidos na matriz.\n");
        printf("0 - Encerrar programa.\n");
        scanf("%d", &option);
 
        switch (option) {
            case 1: 
                fillMatrix(matrix, M, N);
                printMatrix(matrix, M, N);
                break;
 
            case 2:
                biggestVector(matrix, M, N, vector);
                printVector(vector, N);
                break;
 
            case 3:
                a = repeatNumbers(matrix, M, N, &linha, &coluna);
                if (linha > coluna)
                    printf("Linha com mais repetidos: %d\nNúmero de repetições: %d\n", linha, a);
                else
                    printf("Coluna com mais repetidos: %d\nNúmero de repetições: %d\n", coluna, a);
        }
 
    } while (option != 0);
    
    return 0;
}
 
void fillMatrix(int m[M][N], int l, int c) {
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < c; ++j) {
            m[i][j] = rand() % 100 + 1;
        }
    }
}
void printMatrix(int m[M][N], int l, int c) {
    for (int i = 0; i < l; ++i) {
        for (int j = 0; j < c; ++j) {
            printf("%3d ", m[i][j]);
        }
        printf("\n");
    }
}
void biggestVector(int m[M][N], int l, int c, int v[]) {
    for (int j = 0; j < c; ++j) {
        int maior = m[0][j];
        for (int i = 1; i < l; ++i) {
            if (m[i][j] > maior) {
                maior = m[i][j];
            }
        }
        v[j] = maior;
    }
}
void printVector(int v[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
}
 
int repeatNumbers(int m[M][N], int l, int c, int * linha, int * coluna) {
    int tot_linha = 0, tot_coluna = 0;
    *linha = 0, *coluna = 0;

    for (int i = 0; i < l; i++) {
        int linha_atual = 0;
        int found[101] = {0};
        
        for (int j = 0; j < c; j++) {
            int aux = m[i][j];
            if (!found[aux]) {
                found[aux] = 1;
                int count = 1;
                for (int k = j + 1; k < c; k++) {
                    if (m[i][k] == aux) {
                        count++;
                    }
                }
                if (count > 1) {
                    linha_atual += count;
                }
            }
        }

        if (linha_atual > tot_linha) {
            tot_linha = linha_atual;
            *linha = i+1;
        }
    }

    for (int j = 0; j < c; j++) {
        int coluna_atual = 0;
        int found[101] = {0};
        
        for (int i = 0; i < l; i++) {
            int aux = m[i][j];
            if (!found[aux]) {
                found[aux] = 1;
                int count = 1;
                for (int k = i + 1; k < l; k++) {
                    if (m[k][j] == aux) {
                        count++;
                    }
                }
                if (count > 1) {
                    coluna_atual += count;
                }
            }
        }

        if (coluna_atual > tot_coluna) {
            tot_coluna = coluna_atual;
            *coluna = j+1;
        }
    }
    if (tot_coluna > tot_linha){
        *linha=0;
        return tot_coluna;
    }
    *coluna=0;
    return tot_linha;
}
