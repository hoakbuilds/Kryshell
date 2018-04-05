#include "shell.h"

LinkedList *insertFirst(LinkedList *head, char *string){

    LinkedList *novo = malloc(sizeof(LinkedList));
    char *stringlista = malloc((sizeof(char)*1024));

    strcpy(string, stringlista);
    
    novo->next = head;
    novo->string = stringlista;

    return novo;
}

void printhistory(LinkedList *head){
    while(head->next!=NULL){
        printf("%s\n", head->string);
        head=head->next;
    }
}