#include <stdlib.h>
#include <string.h>


struct stack{
    int noe;
    int capacity;
    char * array;
} stack;


int initialize(struct stack * s){
    s->noe=0;
    s->capacity=10000;
    s->array=malloc(10000);
}


char pop(struct stack * s){
    (s->noe)--;
    return (s->array)[(s->noe)];
}


int push(struct stack * s,char value){
    (s->array)[(s->noe)]=value;
    (s->noe)++;
}


int isPalindrome(char * str){
    struct stack s;
    initialize(&s);
    int len = strlen(str);
    int i = 0;
    if(len>1){
        while(i<len/2){
            push(&s, str[i]);
            i++;
        }
        if(len%2!=0) i++;
        while(i<len){
            if(str[i]!=pop(&s)) return 0;
            i++;
        }
    }
    return 1;
}


int main(){
    printf("%d",isPalindrome("hnah"));
}