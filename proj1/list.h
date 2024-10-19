#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// in this file u will find all the functions which are helpful for the list 

typedef struct list_node{
    struct list_node *next;
    char *name;
    int sum;
    char *date;
}Listnode;

typedef struct list{
    Listnode *head;
    Listnode *end;
    int size;
}List; 

// destroy the list
void list_destroy(List* list);

// create the list
List* list_create();

int list_size(List *list);

// insert the new node in the end of the list two insert functions with different use each time 
void list_insert_all(List *list, char *name, int sum, char *date);

void list_insert_node(List *list, char *name);

void list_print(List *list);

void remove_next(List *list, Listnode *node);

// iteration of list
Listnode* list_next(List* list, Listnode* node);

Listnode *list_first(List* list);

Listnode *list_last(List *list);

