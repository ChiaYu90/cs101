#include <stdio.h>
#include <stdlib.h>
typedef struct Linkedlist{
    char data;
    struct Linkedlist* next;
} Linkedlist;

Linkedlist* allocList(char data){
    Linkedlist* a = (Linkedlist*)malloc(sizeof(Linkedlist));
    a->data = data;
    a->next = NULL;
    return a;
}
Linkedlist* appendList(Linkedlist* head, char new_data){
    Linkedlist* new = allocList(new_data); 
    if(head){
        Linkedlist* tmp = head;
        while ((tmp->next)!=NULL)    tmp = tmp ->next;
        tmp->next = new;
    }
    else{
        head = new;
    }
    return head;
}

void showList(Linkedlist* list){
    Linkedlist* tmp = list;
    while (tmp!=NULL){
        printf("[%c]->", tmp->data);
        tmp = tmp ->next;
    }
    printf("->NULL\n"); 
}
Linkedlist* reverseList(Linkedlist* head){
    Linkedlist* new_head;
    while(head!=NULL){
        Linkedlist* tmp = allocList(head->data);
        if(new_head){
            tmp->next = new_head;
            new_head = tmp;
        }
        else{
            new_head = tmp;
        }
        head = head->next;
    }
    return new_head;
}
int main (void){
    Linkedlist* head = NULL;
    head = appendList(head, 'A');
    head = appendList(head, 'B');
    head = appendList(head, 'C');
    head = appendList(head, 'D');
    head = appendList(head, 'E');
    showList(head);
    head = reverseList(head);
    showList(head);
    return 0 ;
}
