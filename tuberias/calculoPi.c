#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    pid_t pid;
    int pipefd[2];
    double pi2[11];

    int r = pipe(pipefd);
    if(r < 0){
        perror("error pipe()");
        exit(-1);
    }
    pid = fork();
    if(pid < 0){
        perror("error fork");
        exit(-1);
    }
    if(pid == 0){
        close(pipefd[0]);
        double *bufer;
        double sec;

        for(int i = 0; i < 10000; i++){
            sec = sec + 1/(i*4.0+1.0);
        }

        bufer = &sec;
        write(pipefd[1], bufer, 10);
        close(pipefd[1]);
        exit(0);
    }else{
        close(pipefd[1]);
        double pi1;

        for(int i = 0; i < 10000; i++){
            pi1 = pi1 - 1/(i*4.0 + 3.0);
        }

        r = read(pipefd[0], pi2, 10);
        pi2[r] = 0;
        close(pipefd[0]);
        printf("\nPI = %f \n", (pi1 + *pi2)*4);
    }
    return 0;
}