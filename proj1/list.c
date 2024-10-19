#include "list.h"
 
List *list_create(){
    List *list = malloc(sizeof(*list));
    if (list == NULL){
        perror("Failed memory allocation!\n");
        exit(EXIT_FAILURE);
    }
    list->size = 0;
    list->head = NULL;
    list->end = NULL;
    return list;
};

void list_insert_all(List *list, char *name, int sum, char *date){
    if (list == NULL)
        return;
    Listnode *new_node = malloc(sizeof(*new_node));
    if (new_node == NULL){
        perror("Allocation's failure!");
        return;
    }
    new_node->name = strdup(name);
    new_node->next = NULL;
    new_node->date = strdup(date);
    new_node->sum = sum;
    if (list->size == 0){
        list->head =new_node;
        list->end = new_node;
    }
    else{
        list->end->next =new_node;
        list->end = new_node;
    }
    list->size++;
};

// function for 1 and 2
void list_insert_node(List *list, char *name){
    if (list == NULL)
        return;
    Listnode *new_node = malloc(sizeof(*new_node));
    if (new_node == NULL){
        perror("Allocation's failure!");
        return;
    }
    new_node->name = strdup(name);
    new_node->next = NULL;
    if (list->size == 0){
        list->head =new_node;
        list->end = new_node;
    }
    else{
        list->end->next =new_node;
        list->end = new_node;
    }
    list->size++;
};

int list_size(List *list){
    if (list == NULL)
        return 0;
    return list->size;
};

void list_destroy(List *list){
    if(list == NULL)
        return;

    Listnode *node = list->head;
    while(node != NULL){
        Listnode *next = node->next;
        free(node->name);
        if(node->date != NULL)
            free(node->date);
        free(node);
        node =next;
    }
    free(list);
};

void list_print(List *list){
    Listnode* curr = list_first(list);
    while(curr != NULL){
        printf("%s\n",curr->name);
        curr = list_next(list,curr);      
    }
};

// the next of the node u guve will be deleted in order to delete the first node just NULL
void list_remove_next(List *list, Listnode* node){
    Listnode *rem;
    if(node == NULL){
        if (list->size == 0)
            return;
        rem = list->head;
        list->head = rem->next;        
    }

    else{
        rem = node->next;
        node->next = rem->next;

        if(list->end == rem)
            list->end = node;
    }

    free(rem->name);
    free(rem);
    list->size--;
};

int main() {
    List *my_list = list_create();

    list_insert_node(my_list, "First element");
    list_insert_node(my_list, "Second element");
    list_print(my_list);
    printf("List size: %d\n", list_size(my_list));  // Should print 2
    list_remove_next(my_list,NULL);
    list_print(my_list);
    printf("List size: %d\n", list_size(my_list));  // Should print
    list_destroy(my_list); // Clean up memory

    return 0;
};


// use for easiest iteration
Listnode* list_first(List* list){
    return list->head;
};

Listnode* list_next(List* list, Listnode* node){
    return node->next;
};

Listnode* list_last(List* list){
    return list->end;
};