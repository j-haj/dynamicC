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

/**
 * Insert the given @p val into the respective list
 *
 * @param list pointer to the list being inserted into
 * @param val @p struct data_t* value being inserted
 *
 * @return @p true if insertion was successful, @p false otherwise
 */
bool list_insert(struct list* list, struct data_t* val);

// TODO: Finish documenting functions
bool list_insert(struct list* list, struct list_node* node);
bool list_append(struct list* list, struct data_t* val);
bool list_append(struct list* list, struct list_node* node);

struct data_t* list_find(struct list* list, struct data_t val);
struct data_t* list_find(struct list* list, struct list_node* node);
bool list_contains(struct list* list, struct data_t val);
bool list_contains(struct list* list, struct list_node* node);

/**
 * Deletes the first occurence of the value @p val by performing a search for
 * the given value and then deleting the first node containing @p val
 *
 * @param list pointer to the respective list
 * @param val @p struct data_t value to be deleted
 *
 * @return @p true if the delete was successful, @p false otherwise
 */
bool list_delete(struct list* list, struct data_t* val);

/**
 * Deletes the node in the list that matches the passed @p node
 *
 * @param list pointer to the respective list struct
 * @param node node to be deleted
 *
 * @return @p true if the deletion was successful, @p false otherwise
 */
bool list_delete(struct list* list, struct list_node* node);

/**
 * Creates a string representation of the list for printing
 *
 * @param list pointer to the list generating the string representation
 *
 * @return @p char* representation of the list
 */
char* list_str(struct list* list);

#endif // __LIST_H
