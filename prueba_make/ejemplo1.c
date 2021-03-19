#include <stdlib.h>
#include <stdio.h>

int main(){
    FILE *f=fopen("out.txt", "w");
    fprintf(f,"5 7\n");
}