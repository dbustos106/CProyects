//%cflags:-lpthread -lm

/** 	compilar con math.h   -lm
** 	compilar con threads: -lpthread
*/

#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

#define MAX_PROCESOS 1
/* Variables para la tuberia*/
pid_t pid;
int r;
char c;
int pipefd[2];

struct datos_tipo{
	int dato;
	int p;
}

* proceso(void *datos)
{
	struct datos_tipo *datos_proceso;
	datos_proceso = (struct datos_tipo *) datos;
	int a, i, j, p;
	
	a = datos_proceso -> dato;
	p = datos_proceso -> p;
	
	read(pipefd[0], &c, 1);

	for(i=0; i <= p; i++){
    printf("%i ",a);}

	fflush(stdout);
	sleep(2);
	for(i=0; i<=p; i++)
	{
		printf("- ");
	}
	fflush(stdout);

	write(pipefd[1], &c, 1);
}

int main()
{
	int error;
	char *valor_devuelto;
	/* Variables para hilos*/
	struct datos_tipo hilo1_datos, hilo2_datos;
	pthread_t idhilo1, idhilo2, idhilo3, idhilo4;

	hilo1_datos.dato = 1;
	hilo2_datos.dato = 2;
	hilo1_datos.p = 10;
	hilo2_datos.p = 5;

    r = pipe(pipefd);
    if(r < 0){
        perror("error pipe()");
        exit(-1);
    }

	c = 'c';
	write(pipefd[1], &c, 1);

	error=pthread_create(&idhilo1, NULL, (void *)proceso, (void *)(&hilo1_datos));
	if (error != 0)
	{
		perror ("No puedo crear hilo");
		exit (-1);
	}

	error=pthread_create(&idhilo2, NULL, (void *)proceso, (void *)(&hilo2_datos));
	if (error != 0)
	{
		perror ("No puedo crear thread");
		exit (-1);
	}
	pthread_join(idhilo2, (void **)&valor_devuelto);
	pthread_join(idhilo1, (void **)&valor_devuelto);

	return 0;
}