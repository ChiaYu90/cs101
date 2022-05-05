#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next; 
} node_t;
node_t* allocate_node(int data){
    node_t* a = (node_t*)malloc(sizeof(node_t));
    a->data = data;
    a->next = NULL;
    return a;
}
node_t* append_node(node_t* list, int new_data){
    node_t* tmp = list; 
    while ((tmp->next)!=NULL){
        tmp = tmp ->next;
    }
    tmp->next = allocate_node(new_data); 
    return list;
}
void show_list(node_t* list ){
    while ((list->next)!=NULL)
    {
        printf("[%d]->", list->data);
        list = list->next;
    }
    printf("[%d]",list->data);
}
void free_all_node(node_t* list){
    node_t* tmp ;
    while ((list->next) !=NULL){
        tmp = list->next;
        free(list);
        list = tmp;
    }
    free(list);
    
}
int main (){
    node_t* head = NULL;
    head = append_node(head, 0);
    show_list(head);
    head = append_node(head, 11);
    show_list(head);
    head = append_node(head, 222);
    show_list(head);
    head = append_node(head, 333);
    show_list(head);
    free_all_node(head);
    return 0;
}
