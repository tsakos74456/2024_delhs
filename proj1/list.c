#include "list.h"

typedef struct list{
    Listnode *start;
    int size;
}List;

typedef struct list_node{
    struct list_node *next;
    int data;
}Listnode;

List create(){
    List *list = malloc(sizeof(List));
    list->size = 0;
    list->start = NULL;
}

void insert_next(List list, Listnode *node, int data){
    Listnode *new_node = malloc(sizeof(*new_node));
    new_node->data = data;
    new_node->next = NULL;
    if (list.size == 0){
        list.start = new_node;
        return;
    }
    else{
        new_node->next = node->next;
        node->next = new_node;
    }

}