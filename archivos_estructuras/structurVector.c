#include<stdio.h>
#include<stdlib.h>
//comentario
struct vector{
    int len;
    int currentLength;
    int *elements;
};

void init(struct vector *y, int len){
    y->currentLength = 0;
    y->len = len; 
    y->elements=malloc(len*sizeof(int));
}

void add(struct vector *y, int el){
    if(y->len==y->currentLength){
        int *aux=malloc(y->len*2*sizeof(int));
        for(int i = 0; i < y->len; i++){
            *(aux + i) = *(y->elements + i);
        }
        *(aux+y->len) = el;
        y->len *= 2;
        y->currentLength+=1;
        free(y->elements);
        y->elements=aux;
    }else{
        *(y->elements+y->currentLength)=el;
        y->currentLength+=1;
    }
}

int get(struct vector *y, int pos){
    if(pos >= y->currentLength){
        return -1;
    }else{
        return *(y->elements + pos);
    }
}

void pop(struct vector *y){
    if(y->currentLength == 0){
        return;
    }else{
        y->currentLength-=1;
    }
}

void pop_pos(struct vector *y, int pos){
    int* aux = malloc(y->len*sizeof(int));
    int j = 0;
    if(pos >= 0 && pos < y->currentLength){
        for(int i = 0; i < y->currentLength; i++){
            if(i != pos){
                *(aux+j) = *(y->elements+i);
                j+=1;
            }
        }
        free(y->elements);
        y->currentLength-=1;
        y->elements=aux;
    }else{
        printf("EL indice no existe");
    }
}

int main(){
    struct vector v;
    init(&v,3);
    add(&v,1);
    add(&v,2);
    add(&v,3);
    add(&v,4);
    add(&v,5);
    add(&v,6);
    printf("Este numero: %d", get(&v,0));
    printf("Este numero: %d", get(&v,5));
    pop(&v);
    printf("Este numero: %d", get(&v,5));
    printf("Este numero: %d", get(&v,2));
    pop_pos(&v,2);
    printf("Este numero: %d", get(&v,2));
    return 0;
}