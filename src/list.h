#ifndef __LIST_H
#define __LIST_H

#include <stdlib.h>
#include <stdbool.h>

#include "data.h"

/**
 * Struct that corresponds to the nodes of the linked list_t*. Uses @p data_t as
 * the value to allow the user to avoid having to cast via void *
 */
struct node_t {
	struct data_t value;
	struct node_t *next;
};

/**
 * Struct for @p list_t* - linked list_t*s
 */
struct list_t *
{
	struct node_t *head;
	struct node_t *tail;
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
bool nodecmp(struct node_t *n1, struct node_t *n2);

/**
 * Creates an empty @p struct node_t*
 *
 * @return @p struct node_t* with no data
 */
struct node_t *create_node();

/**
 * Deletes a @p node_t struct
 *
 * @param node @p node_t to delete
 */
void delete_node(struct node_t *node);

/**
 * Creates a @p struct list_t*_node_t* with contents @p val
 *
 * @param val a @p struct data_t value that represents the node's data
 *
 * @return @p struct list_t*_node_t* with the given data
 */
struct node_t *create_node(struct data_t val);

/**
 * Create an empty linked list_t*
 *
 * @return @p struct list_t** pointer to list_t*
 */
struct list_t *create_list();

/**
 * Create an empty linked list_t* of size @p size
 *
 * @param size size of the list_t*
 *
 * @return @p struct list_t** pointer to list_t*
 */
struct list_t *create_list_t *(long size);

/**
 * Create a linked list_t* pointing to @p struct list_t*_node_t n
 *
 * @param n @p struct_list_t*_node_t* head of the newly created linked list_t*
 *
 * @return @p struct list_t** pointer to list_t*
 */
struct list_t *create_list(struct node_t *n);

/**
 * Insert the given @p val into the respective list_t*
 *
 * @param list_t* pointer to the list_t* being inserted into
 * @param val @p struct data_t* value being inserted
 *
 * @return @p true if insertion was successful, @p false otherwise
 */
bool list_insert(struct list_t **list, struct data_t *val);

/**
 * Insert the given @p node into  the beginning of the respective list_t*.
 *
 * @param list_t* pointer to the list_t* being inserted into
 * @param node node being inserted
 *
 * @return @p true if insertion was successful, @p false otherwise
 */
bool list_insert(struct list_t *list, struct node_t *node);

/**
 * Append @p val to the end of the list_t*
 *
 * @param list_t* pointer to the list_t* being appended to
 * @param val value sed to create a node that is appended to the list_t*
 *
 * @return @p true if successful, @p false otherwise
 */
bool list_append(struct list_t **list, struct data_t val);

/**
 * Append @p node to the end of the list_t*
 *
 * @param list_t* pointer to the list_t* being appended to
 * @param node node being appended
 *
 * @return @p true if successful, @p false otherwise
 */
bool list_t *_append(struct list_t **list_t *, struct list_t *_node_t *node);

/**
 * Searches the list_t* for a node with the given value, returning a
 * pointer to the first node containing @p val
 *
 * @param list_t* list_t* being searched
 * @param val value being searched for
 *
 * @return pointer to the first node encountered whose data matches @p val
 */
struct data_t *list_t *_find(struct list_t **list_t *, struct data_t val);

/**
 * Determines whether the given list_t* contains @p val. Search complexity is
 * O(n), since the list_t* is searched via traversal
 *
 * @param list_t* the list_t* bein searched
 * @param val the value being searched for
 *
 * @return @p true if the value was found, @p false otherwise
 */
bool list_t *_contains(struct list_t **list_t *, struct data_t val);

/**
 * Determines whether the given list_t* contains @p node. The search complexity
 * is O(n), since the list_t* is searched via traversal.
 *
 * @param list_t* the list_t* being searched
 * @param node the node being searched for
 *
 * @return @p true if the node is found, @p false otherwise
 */
bool list_t *_contains(struct list_t **list_t *, struct list_t *_node_t *node);

/**
 * Deletes the first occurence of the value @p val by performing a search for
 * the given value and then deleting the first node containing @p val
 *
 * @param list_t* pointer to the respective list_t*
 * @param val @p struct data_t value to be deleted
 *
 * @return @p true if the delete was successful, @p false otherwise
 */
bool list_t *_delete(struct list_t **list_t *, struct data_t val);

/**
 * Deletes the node in the list_t* that matches the passed @p node
 *
 * @param list_t* pointer to the respective list_t* struct
 * @param node node to be deleted
 *
 * @return @p true if the deletion was successful, @p false otherwise
 */
bool list_t *_delete(struct list_t **list_t *, struct list_t *_node_t *node);

/**
 * Creates a string representation of the list_t* for printing
 *
 * @param list_t* pointer to the list_t* generating the string representation
 *
 * @return @p char* representation of the list_t*
 */
char *list_t *_str(struct list_t **list_t *);

#endif // __LIST_H
