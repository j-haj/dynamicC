#ifndef __LIST_H
#define __LIST_H

#include <stdlib.h>
#include <stdbool.h>

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
 * Compares nodes @p n1 and @p n2 for equality. Note that only the node values
 * are compared. Comparing the @p next pointers would require O(n) operations
 *
 * @param n1 first node for comparison
 * @param n2 second node for comparison
 *
 * @return @p true if nodes are equal, @p false otherwise
 */
bool list_node_cmp(struct list_node* n1, struct list_node* n2);

/**
 * Creates an empty @p struct list_node*
 *
 * @return @p struct list_node* with no data
 */
struct list_node* create_node();

/**
 * Deletes a @p list_node struct
 *
 * @param node @p list_node to delete
 */
void delete_node(struct list_node* node);

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

/**
 * Insert the given @p node into  the beginning of the respective list.
 *
 * @param list pointer to the list being inserted into
 * @param node node being inserted
 *
 * @return @p true if insertion was successful, @p false otherwise
 */
bool list_insert(struct list* list, struct list_node* node);

/**
 * Append @p val to the end of the list
 *
 * @param list pointer to the list being appended to
 * @param val value sed to create a node that is appended to the list
 *
 * @return @p true if successful, @p false otherwise
 */
bool list_append(struct list* list, struct data_t val);

/**
 * Append @p node to the end of the list
 *
 * @param list pointer to the list being appended to
 * @param node node being appended
 *
 * @return @p true if successful, @p false otherwise
 */
bool list_append(struct list* list, struct list_node* node);

/**
 * Searches the list for a node with the given value, returning a 
 * pointer to the first node containing @p val
 *
 * @param list list being searched
 * @param val value being searched for
 *
 * @return pointer to the first node encountered whose data matches @p val
 */
struct data_t* list_find(struct list* list, struct data_t val);

/**
 * Determines whether the given list contains @p val. Search complexity is O(n),
 * since the list is searched via traversal
 *
 * @param list the list bein searched
 * @param val the value being searched for
 *
 * @return @p true if the value was found, @p false otherwise
 */
bool list_contains(struct list* list, struct data_t val);

/**
 * Determines whether the given list contains @p node. The search complexity is
 * O(n), since the list is searched via traversal.
 *
 * @param list the list being searched
 * @param node the node being searched for
 *
 * @return @p true if the node is found, @p false otherwise
 */
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
bool list_delete(struct list* list, struct data_t val);

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
