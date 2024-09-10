#include <stdio.h>
#define n 2
int oddNumbers(int m[][n]);
void fillMatrix(int m[][n]);


int main(){

    int m[n][n], k = 0;


    printf("Insira os elementos:\n");
    fillMatrix(m);


    k = oddNumbers(m);
    printf("Impares %d", k);

}

int oddNumbers(int m[][n]){
    int k = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(m[i][j] % 2 != 0){
                k++;
            }
        }
    }
    return k;
}

void fillMatrix(int m[][n]){
    for(int i = 0; i < n; i++){
        for(int k = 0; k < n; k++){
            scanf("%d", &m[i][k]);
        }
    }
}
