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
node_t* append_node(node_t* head, int new_data){
    node_t* new = allocate_node(new_data); 
    if(head){
        node_t* tmp = head;
        while ((tmp->next)!=NULL)    tmp = tmp ->next;
        tmp->next = new;
    }
    else{
        head = new;
    }
    return head;
}
node_t*  add_node(node_t* head, int new_data){
    node_t* tmp = allocate_node(new_data);
    tmp->next = head;
    head = tmp;
    return head;
}
node_t*  del_node(node_t* head, int n){
    node_t* tmp = head, *tmp2;
    if(n){
        for(int i=0; i<n-1; i++)     tmp = tmp->next;
        tmp2 = tmp->next;
        tmp->next = tmp2->next;
        free(tmp2);
        tmp2 = NULL;
    }
    else{
        head = head->next;
        free(tmp);
    }
    return head;
}
void show_list(node_t* list){
    node_t* tmp = list;
    while (tmp!=NULL){
        printf("[%d]->", tmp->data);
        tmp = tmp ->next;
    }
    printf("null\n"); 
}
void free_all_node(node_t* head){
    node_t* p = NULL;
    while (head){
        p = head;
        head = head->next;
        printf("free([%d])->",p->data);
        free(p);
        p = NULL;
    }
    printf("null\n");
}

int main (){
    node_t* head = NULL;
    head = append_node(head, 0);
    show_list(head);
    head = append_node(head, 1);
    show_list(head);
    head = add_node(head, -1);
    show_list(head);
    del_node(head, 1);
    show_list(head);
    free_all_node(head);
    //printf("%d", head->next->data);
    return 0;
}
