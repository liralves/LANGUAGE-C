#include <stdio.h>
#define TAM 20
 
void preencherDigito(int[], int);
void imprimirVetor(int[], int);
 
int main()
{
    int nVector[TAM], num = 0;

    printf("Digite\n");
    scanf("%d", &num);
    preencherDigito(nVector, num);
    imprimirVetor(nVector, TAM);

    return 0;
}
 
 void preencherDigito(int v[], int num){
    for(int i = TAM - 1; i >= 0; i--){
        v[i] = num % 10;
        num /= 10;
    }
    if(num >= TAM){
        printf("ERRO. Não é possivel inserir esses digitos:\n");
    }
 }

 void imprimirVetor(int v[], int tam){
    for(int i = 0; i < tam; i++){
        printf("%d", v[i]);
    }
    printf("\n");
 }