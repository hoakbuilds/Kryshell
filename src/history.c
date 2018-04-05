#include "shell.h"

LinkedList *insertLast(LinkedList *head, char *string){
    LinkedList *aux = head;
    while(aux != NULL){
        aux=aux->next;
    }
    aux.next = createNode(char *string);
    return head;
}

LinkedList *createNode(char *string){

    LinkedList node;

    node->next=NULL;
    node->string=string;

    return node;
}

void history(LinkedList *head){
    while(head!=NULL){
        printf("%s", head->string);
    }
}