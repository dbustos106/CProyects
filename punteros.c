#include<stdio.h>
#include<stdlib.h>

int main(){
    int arr[16] = {1,2,3,4,5,6,7};
    int *p = arr;
    //int &c; la referencia es constante, no cambia.
    printf("El dato de arr[3] es: %d\n", *(p + 1));
    printf("El direccion de arr[3] es: %p\n", p);
    return 0;
}