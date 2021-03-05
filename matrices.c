#include<stdio.h>
#include<stdlib.h>

#define rows 3
#define cols 3

int main(){
    int arr[rows][cols] = {{1,2,3},{4,5,6},{7,8,9}};
    int **p = malloc(3*sizeof(int *));
    
    for(int i = 0; i < 3; i++){
        *(p + i) = malloc(3*sizeof(int));
    }

    int num = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            *(*(p + i) + j) = num++; 
            printf("EL elemento es: %d\n", *(*(p + i) + j));
        }
    }

    // liberar
    free(p);
    return 0;
}