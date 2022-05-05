#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next; 
} node_t;
node_t* allocate_node(int data){
    node_t* a = (node_t*)malloc(sizeof(node_t));
    a->data = data;
    //printf("%d",a->data);
    a->next = NULL;
    return a;
}
node_t* append_node(node_t* list, int new_data){
    node_t* tmp = list; 
    if((list) == NULL){
        list = allocate_node(new_data); 
        return list;
    }
    while ((tmp->next)!=NULL){
        tmp = tmp ->next;
    }
    tmp->next = allocate_node(new_data);
     //printf("%p",tmp); 
    //printf("%d",(tmp->next)->data);
    return list;
}
void show_list(node_t* list){
    node_t* tmp = list;
    while (tmp!=NULL){
        printf("[%d]->", tmp->data);
        tmp = tmp ->next;
    }
    printf("null\n"); 
}
void free_all_node(node_t* list){
    if(list == NULL)    return;
    free_all_node(list->next);
    free(list);
}

int main (){
    node_t* head = NULL;
   // head ->next = NULL
    head = append_node(head, 0);
   
    show_list(head);
    head = append_node(head, 11);
    //printf("[%d]->", head->data);
    show_list(head);
    head = append_node(head, 222);
    show_list(head);
    head = append_node(head, 3333);
    show_list(head);
    free_all_node(head);
    //printf("%p", head->next);
    return 0;
}
