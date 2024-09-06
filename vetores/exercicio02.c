#include <stdio.h>
#define CAPAC 50
void fillVector(int[], int);
void printVector(int v[], int);
int binarySearch(int[], int, int);

int main(){

    int vector[CAPAC], size = 0, opt = 0, value = 0, x;

    do{
        printf("Enter with size of vector (3 and %d):\n", CAPAC);
        scanf("%d", &size);
    }while(size < 1 || size > CAPAC);

    printf("Enter with the elements (separated by spaces):\n");
    fillVector(vector, size);

    do{
        printf("\n1 - Print.\n");
        printf("2 - Search.\n");
        printf("3 - Remove.\n");
        printf("4 - Fill in.\n");
        printf("5 - Exit.\n");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            printVector(vector, size);
            break;

        case 2: {
            printf("Element to consult the position:\n");
            scanf("%d", &value);
            x = binarySearch(vector, size, value);
            if(x != -1){
                printf("Element found in position %d.\n", x);
            }else {
                printf("Element not found.\n");
            }
        }
        case 3:
            
        default:
            break;
        }

    }while(opt != 5);

}

int binarySearch(int v[], int size, int value){
    int left = 0, right = size - 1, mid = 0;

    while(left <= right){
        mid = (right + left) / 2;
        if(value < v[mid]){
            right = mid - 1;
        }else if(value > v[mid]){
            left = mid + 1;
        }else {
            return mid;
        }
    }
    return -1;

}

void fillVector(int v[], int size){
    char last;
    for(int i = 0; i < size; i++){
        do{
        scanf("%d%c", &v[i], &last);
        }while(last == '\0');
        int j = i;
        while(j > 0 && v[j] < v[j-1]){
            int aux = v[j];
            v[j] = v[j - 1];
            v[j - 1] = aux;
            j--;
        }
    }
}

void printVector(int v[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", v[i]);
    }
}


