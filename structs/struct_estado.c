#include <stdio.h>
#define LEN 26   

typedef struct{
    char estado[20];
    int veiculos;
    int acidentes;
}INFO;

void preencherInfo(INFO info[]);
void acidentes(INFO info[], int *indexMaior, int *indexMenor);
int percentualAcidentes(INFO info[],int index);
int calcularMedia(INFO info[]);
void acimaDaMedia(INFO info[], int media);

int main(){
    int op, maior, menor, index, media;
    INFO info[LEN];
        
    do{
        printf("\n1. Cadastrar Estados.\n2. Verificar estados com mais e menos acidentes.\n3. Verificar percentual de acidentes de um estado.\n4. Verificar a media de acidentes no país.\n5. Verificar quais estados estão acima da média de acidentes no país.\n0. Sair\n");
        scanf("%d",&op);
        switch (op){
            case 1:
                preencherInfo(info);
                break;
            case 2:
                acidentes(info, &maior, &menor);
                printf("O estado com mais acidentes foi: %s, com %d acidentes totais", info[maior].estado, info[maior].acidentes);
                printf("O estado com menos acidentes foi: %s, com %d acidentes totais", info[menor].estado, info[menor].acidentes);
                break;
            case 3:
                printf("Escolha o número do estado que você quer Verificar:\n");
                scanf("%d", &index);
                percentualAcidentes(info, index);
                break;
            case 4:
                media = calcularMedia(info);
                printf("A média de acidentes no país foi de: %d", media);
                break;
            case 5:
                media = calcularMedia(info);
                acimaDaMedia(info, media);
                break;
            case 0:
                break;
            default:
                printf("Entrada inválida. Tente algum dos valores citados");
        }
    }while(op != 0);


    return 0;
}

void preencherInfo(INFO info[]){
     
    for(int i = 0; i < LEN; i++){
        printf("Estado: \n");
        scanf("%s", info[i].estado);
        printf("N de veiculos (2007): \n");
        scanf("%d", &info[i].veiculos);
        printf("N de acidentes (2007): \n");
        scanf("%d", &info[i].acidentes);
    }
}

void acidentes(INFO info[], int *indexMaior, int *indexMenor){
    int maior = info[0].acidentes, menor = info[0].acidentes;
    (*indexMaior) = 0;
    (*indexMenor) = 0;
    
    for(int j = 1; j < LEN; j++){
        
        if(maior < info[j].acidentes){
            
            maior = info[j].acidentes;
            (*indexMaior) = j;
        }
        if(menor > info[j].acidentes){
            
            menor = info[j].acidentes;
            (*indexMenor) = j;
        }
    }
}

int percentualAcidentes(INFO info[],int index){
    
    if (info[index].veiculos == 0) return 0;
    
    int percentual = info[index].acidentes/info[index].veiculos;
    return percentual;

}

int calcularMedia(INFO info[]){
    int soma = 0;
    
    for (int i = 0; i <LEN; i++){
        soma += info[i].acidentes;
    }
    
   int media = soma/LEN;
    
    return media;
}

void acimaDaMedia(INFO info[], int media){
    
    printf("Os estados: ");
    for (int i = 0; i < LEN; i++){
        if(info[i].acidentes>media){
            printf("%s\n", info[i].estado);
        }
    }
    printf("Estão acima da média nacional de acidentes!");
}