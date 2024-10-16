#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 80

void remove_espaco(char *string);
void remove_linha(char *string);
int palindromo(char *string);

int main()
{
    char array[TAM];
    
    fgets(array, TAM, stdin);
    
    remove_espaco(array);
    remove_linha(array);
    
    if(palindromo(array)){
        printf("É PALINDROMO.\n");
    }else{
        printf("NÃO É PALINDROMO.\n");
    }
    
    return 0;
}

void remove_espaco(char *string){
    char string2[TAM];
    int len = strlen(string);
    int j = 0;
    for(int i = 0; i < len; i++){
        if(string[i] != ' '){
            string2[j]=string[i];
            j++;
        }
    }
    string2[j] = '\0';
    strcpy(string, string2);
}

int palindromo(char *string){
    
    char string_reverse[TAM];
    int len = strlen(string);
    int j = 0;
    
    for(int i = len - 1; i >= 0; i--){
        string_reverse[j] = string[i];
        j++;
    }
    
    string_reverse[j] = '\0';
    
    if(strcmp(string_reverse, string) == 0){
        return 1;
    }else{
        return 0;
    }
}

void remove_linha(char *string){
    int len = strlen(string);

    if (len > 0 && string[len - 1] == '\n') {
        string[len - 1] = '\0';
    }
}
