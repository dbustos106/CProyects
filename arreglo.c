#include<stdio.h>
#include<stdlib.h>

int main(){
    int arr[10];
    int *p = malloc(10*sizeof(int));
    int i = 0;
    for(i = 1; i <= 10; i++){
        arr[i - 1]=i;
    }
    for(i = 0; i < 10; i++){
        *(p+i) = i+1;
    }
    printf("direcciones arr\n");
    for(i = 0; i < 10; i++){
        printf("%p", &arr[i]);
    }
    printf("\ndirecciones p\n");
    for(i = 0; i < 10; i++){
        printf("%p", (p+i));
    }
    // liberar
    free(p);
    return 0;
}