#include "list.h"

bool list_node_cmp(struct list_node *n1, struct list_node *n2)
{
	if (n1->value != n2->value)
		return false;
	return true;
}

struct list_node *create_node(struct data_t val)
{
	struct list_node *node =
		(struct list_node *)malloc(sizeof(struct list_node));
	node->value = val;
	return node;
}

struct list *create_empty_list()
{
	struct list *l = (struct list *)malloc(sizeof(struct list));
	return l;
}

struct list *create_allocated_list(long n)
{
	struct list *l = (struct list *)malloc(sizeof(struct list));
	for (long i = 0; i < n; ++i) {
		struct list_node *tmp_node = create_node();
		list_insert(l, tmp_node);
	}
	return l;
}

struct list *create_list_from_node(struct list_node *n)
{
	struct list *l = (struct list *)malloc(sizeof(struct list));
	l->head = n;
	l->tail = n;
	++l->size;
	return l;
}

bool list_insert(struct list *list, struct data_t *val)
{
	struct list_node *n =
		(struct list_node *)malloc(sizeof(struct list_node));
	n->next = l->head;
	l->head = n;
	if (l->head == NULL)
		return false;
	++l->size;
	return true;
}

bool list_insert(struct list *list, struct list_node *node)
{
	node->next = l->head;
	l->head = node;
	if (l->head == NULL)
		return false;
	++list->size;
	return true;
}

bool list_append(struct list *list, struct data_t *val)
{
	struct list_node *n = create_node(val);
	list->tail->next = n;
	list->tail = n;
	if (list->tail == NULL)
		return false;
	++list->size;
	return true;
}

bool list_append(struct list *list, struct list_node *node)
{
	list->tail->next = node;
	list->tail = node;
	if (list->tail == NULL)
		return false;
	return true;
}

struct data_t *list_find(struct list *list, struct data_t val)
{
	struct list_node *tmp_nd = list->head;
	long count = 0;
	long max_iter = list->size;
	while (tmp_nd != NULL && count < max_iter) {
		if (data_t_cmp(tmp_nd->value, val))
			break;
		tmp_nd = tmp_nd->next;
		++count;
	}
	return list_node;
}

bool list_contains(struct list *list, struct data_t val)
{
	if (list_find(list, val) == NULL)
		return false;
	return true;
}

bool list_contains(struct list *list, struct list_node *node)
{
	if (list_find(list, node->value) == NULL)
		return false;
	return true;
}

bool list_delete(struct list *list, struct data_t val)
{
	struct list_node *cur_node = list->head;
	struct list_node *prior_node = NULL;
	long node_index = 0;
	while (!data_t_cmp(cur_node->value, val)) {
		prior_node = cur_node;
		cur_node = cur_node->next;
		++node_index;
	}

	// Handle edge cases where node is head or tail
	if (node_index == 0) {
		list->head = list->head->next;
		else if (node_index == list->size - 1) list->tail = prior_node;
		else prior_node->next = cur_node->next;

		delete_node(cur_node);
		--list->size;
	}
}
bool list_delete(struct list *list, struct list_node *node)
{
}

char *list_str(struct list *list)
{
}
