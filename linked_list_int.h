#ifndef LINKED_LIST_INT_H
#define LINKED_LIST_INT_H

struct linked_list_int_node {
  int value;
  struct linked_list_int_node *prev, *next;
};

struct linked_list_int {
  unsigned int size;
  struct linked_list_int_node *first, *last;
};


struct linked_list_int *linked_list_create();


int linked_list_get(struct linked_list_int *list, int index);


unsigned int linked_list_push_back(struct linked_list_int *list, int value);


unsigned int linked_list_pop_back(struct linked_list_int *list);


unsigned int linked_list_size(struct linked_list_int *list);


int linked_list_find(struct linked_list_int *list, int element);


unsigned int linked_list_insert_at(struct linked_list_int *list, int index, int value);


unsigned int linked_list_remove_from(struct linked_list_int *list, int index);


unsigned int linked_list_capacity(struct linked_list_int *list);


double linked_list_percent_occupied(struct linked_list_int *list);


void linked_list_destroy(struct linked_list_int *list);

#endif