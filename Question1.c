#include <stdio.h>
#include <stdlib.h>


typedef struct node {
int data;
struct node* next;
} node;


node * addToFront(node ** ppHead, int data){
    node * newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->next=*ppHead;
    *ppHead=newNode;
    return newNode;
}


void insertAfterN(node* Head, int M, int N){
    node * tmp = Head;
    if(tmp!=NULL){
        if(Head->data==N){
            Head = addToFront(&(Head->next),M);
        }
        insertAfterN(Head->next,M,N);
    }
}


void printList(node * Head){
    node* tmp = Head;
    while(tmp!=NULL){
        printf("%d ",tmp->data);
        tmp=tmp->next;
    }
}


int main(){
    node * Head = NULL;
    addToFront(&Head,5);
    addToFront(&Head,6);
    addToFront(&Head,6);
    addToFront(&Head,4);
    addToFront(&Head,6);
    addToFront(&Head,3);
    printf("Original list is: ");
    printList(Head);
    printf("\nNew list is: ");
    insertAfterN(Head,200,6);
    printList(Head);
}