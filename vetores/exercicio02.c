#include <stdio.h>
#define CAPAC 50
void fillVector(int[], int);
void printVector(int v[], int);
int removeElement(int[], int, int);
int binarySearch(int[], int, int);
void fillElement(int[], int, int, int);

int main(){

    int vector[CAPAC], size = 0, opt = 0, value = 0, x = 0, y = 0, z = 0, position = 0;

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
                printf("Element found in position %d.\n", (x+1));
            }else {
                printf("Element not found.\n");
            }
        }
        case 3:
            printf("Position of the element to be removed:\n");
            scanf("%d", &value);
            y = removeElement(vector, size, value);
            size--;
            printVector(vector, size);
            break;
        case 4:
            printf("Value to be entered and the position:\n");
            scanf("%d", &value);
            scanf("%d", &position);
            fillElement(vector, size, value, position);
            size++;
            break;
        case 5:
            break;

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
    int aux;
    for(int i = 1; i < size + 1; i++){
        scanf("%d", &v[i]);
        aux = v[i];
        int j;
        for(j = i; (j > 0) && (aux < v[j - 1]); j--){
            v[j] = v[j -1];
        }
        v[j] = aux;
    }
}

void printVector(int v[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", v[i]);
    }
}


int removeElement(int v[], int size, int Rvalue){
    int x = v[Rvalue];
    for(int j = Rvalue + 1; j < size; j++){
        v[j - 1] = v[j];
    }
    return x;
}

void fillElement(int v[], int size, int value, int index){
    for(int j = size; j > index; j--){
        v[j] = v[j -1];
    }
    v[index] = value;
}