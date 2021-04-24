//%cflags:-lpthread -lm
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
 
#define NUM_HILOS 16
double result[NUM_HILOS];

int* funcion(void *datos){
    int *datosh;
    datosh = datos;
    
    if(*datosh < 8){
        for(int i = (*datosh*10000)/8; i < ((*datosh + 1)*10000)/8; i++){
            result[*datosh] = result[*datosh] + 1/(i*4.0 + 1.0);
        }
    }else{
        for(int i = ((*datosh-8)*10000)/8; i < ((*datosh-8 + 1)*10000)/8; i++){
            result[*datosh] = result[*datosh] - 1/(i*4.0 + 3.0);
        }
    }

    return 0;
}
 
int main(){
    pthread_t hilo[NUM_HILOS];
    int datosh[NUM_HILOS];
    int r, *rh0;

    for(int i = 0; i < NUM_HILOS; i++){
        datosh[i] = i;
    }

    for(int i = 0; i < NUM_HILOS; i++){
        r = pthread_create(&hilo[i], NULL, (void *)funcion, (void *)&datosh[i]);
        if(r != 0){
            perror("\n-->pthread_create error: ");
            exit(-1);
        }
    }
    
    for(int i = 0; i < NUM_HILOS; i++){
        r = pthread_join(hilo[i], (void **)&rh0);
        if(r != 0){
            perror("\n-->pthread_join error: ");
            exit(-1);
        }
    }

    double sum = 0;
    for(int i = 0; i < NUM_HILOS; i++){
        sum = sum + result[i];
    }
    printf("PI = %f", sum*4);

    printf("\n");
    return 0;
}