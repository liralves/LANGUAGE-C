#include <stdio.h>
#define L 10
#define C 10

void orderMatrix(int*, int*);
void printMatrix(int[][C], int, int);
void multMatrix(int[][C], int, int, int[][C], int, int, int[][C]);
void fillMatrix(int[][C], int, int);

int main()
{

    int matrixA[L][C], matrixB[L][C], mtMatrix[L][C], lA = 0, cA = 0, lB = 0, cB = 0;
    
    orderMatrix(&lA, &cA);
    fillMatrix(matrixA, lA, cA);
    
    orderMatrix(&lB, &cB);
    fillMatrix(matrixB, lB, cB);
    
    multMatrix(matrixA, lA, cA, matrixB, lB, cB, mtMatrix);
    
    printMatrix(mtMatrix, lA, cB);
    
    
    return 0;
}


void multMatrix(int matrixA[L][C], int lA, int cA, int matrixB[L][C], int lB, int cB, int mtMatrix[L][C]){
    for(int i = 0; i < lA; i++){
        for(int j = 0; j < cB; j++){
            mtMatrix[i][j] = 0;
            for(int k = 0; k < cA; k++){
                mtMatrix[i][j] += matrixA[i][k] * matrixB[k][j]; 
            }
        }
    }
}



void orderMatrix(int *l, int *c){
    printf("ROWS:\n");
    scanf("%d", l);
    
    printf("COLUMNS:\n");
    scanf("%d", c);
}
void fillMatrix(int matrix[L][C], int l, int c){
    for(int i = 0; i < l; i ++){
        for(int j = 0; j < c; j++){
            printf("[%d][%d] = ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}
void printMatrix(int matrix[L][C], int l, int c){
    for (int i = 0; i < l; ++i) {
        for(int j = 0; j < c; j++){
            printf("%d\t", matrix[i][j]);
        }
    }
    printf("\n");
}