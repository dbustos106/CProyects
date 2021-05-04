#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    pid_t pid;
    int r;
    int pipefd[2];
    char puf[11];

    r = pipe(pipefd);
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
        r = write(pipefd[1], "hola mundo\n", 10);
        close(pipefd[1]);
        exit(0);
    }else{
        close(pipefd[1]);
        r = read(pipefd[0], puf, 10);
        puf[r] = 0;
        close(pipefd[0]);
        printf("\nMensaje del hijo: %s \n", puf);
    }
    return 0;
}