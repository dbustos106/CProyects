//%cflags:-lpthread -lm

/* Ejemplo de manejo de hilos
*   compilar con threads: -lpthread
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


#define MAX_PROCESOS 1
#define NUM_HILOS 18

struct datos_tipo{
    int dato;
    int p;
};

pthread_mutex_t mutex;

void * proceso(void *datos){
    struct datos_tipo *datos_proceso;
    datos_proceso = (struct datos_tipo *) datos;
    int a, i, j, p;
    a = datos_proceso -> dato;
    p = datos_proceso -> p;
    
    // Se vuelve bloqueante la sección
    pthread_mutex_lock(&mutex);

    for(i=0; i <= p; i++){
        printf("%i ",a);
    }
    fflush(stdout);
    sleep(3);

    for(i=0; i<=p; i++){
        printf("- ");
    }
    fflush(stdout);

    // Se desbloquea la sección
    pthread_mutex_unlock(&mutex);
}

/*
1.  Imprime primero todos los numeros que se generan por el primer 
    for en cada uno de los hilos, y luego imprime todos los delimitadores
    que se generan por el segundo for en cada uno de los hilos.

2.  Imprime de manera intercalada el conjunto de números y delimitadores 
    generados por cada hilo.
*/

int main(){
    int error, i;
    char *valor_devuelto;

    /* Variables para hilos*/
    struct datos_tipo hilo_datos[NUM_HILOS];
    pthread_t idhilo[NUM_HILOS];
    
    /* Inicializamos los datos */
    for(i=0; i<NUM_HILOS; i++){
        hilo_datos[i].dato = i;
        hilo_datos[i].p = i+1;
    }

    // Se crean las variables de control para la sección crítica
    pthread_mutex_init(&mutex, NULL);

    /*se lanzan los hilos*/
    for(i=0; i < NUM_HILOS; i++){
        error=pthread_create(&idhilo[i], NULL, (void *)proceso, (void *)(&hilo_datos[i]));
        if (error != 0){
            perror ("No puedo crear hilo");
            exit (-1);
        }
    }
    /*Se espera a que terminen hilos*/
    for(i=0; i< NUM_HILOS; i++){
        pthread_join(idhilo[i], (void **)&valor_devuelto);
    }

    // Se destruyen las variables de control de la sección crítica
    pthread_mutex_destroy(&mutex);

return 0;
}