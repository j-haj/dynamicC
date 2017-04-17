#ifndef __LIST_H
#define __LIST_H

#include "data.h"

/**
 * Struct that corresponds to the nodes of the linked list. Uses @p data_t as
 * the value to allow the user to avoid having to cast via void *
 */
struct list_node {
  struct data_t value;
  struct list_node* next;
};

/**
 * Struct for @p list - linked lists
 */
struct list {
  struct list_node* head;
  struct list_node* tail;
  long size;
};

/**
 * Creates an empty @p struct list_node*
 *
 * @return @p struct list_node* with no data
 */
struct list_node* create_node();

/**
 * Creates a @p struct list_node* with contents @p val
 *
 * @param val a @p struct data_t value that represents the node's data
 *
 * @return @p struct list_node* with the given data
 */
struct list_node* create_node(struct data_t val);

/**
 * Create an empty linked list
 *
 * @return @p struct list* pointer to list
 */
struct list* create_list();

/**
 * Create an empty linked list of size @p size
 *
 * @param size size of the list
 *
 * @return @p struct list* pointer to list
 */
struct list* create_list(long size);

/**
 * Create a linked list pointing to @p struct list_node n
 *
 * @param n @p struct_list_node* head of the newly created linked list
 *
 * @return @p struct list* pointer to list
 */
struct list* create_list(struct list_node* n);

bool list_insert(struct list* list, struct data_t* val);
bool list_insert(struct list* list, struct list_node* node);
bool list_append(struct list* list, struct data_t* val);
bool list_append(struct list* list, struct list_node* node);




#endif // __LIST_H
