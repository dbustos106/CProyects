#include <stdlib.h>
#include <stdio.h>

int main(){
    FILE *f=fopen("out.txt", "r");
    int a,b;
    fscanf(f, "%d", &a);
    fscanf(f, "%d", &b);
    printf("suma: %d", a+b);
}