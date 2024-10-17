#include <stdio.h>
#include <stdbool.h>

bool is_empty(List list);

List create();

int list_size(List list);

void insert_next(List list, Listnode node, int data);