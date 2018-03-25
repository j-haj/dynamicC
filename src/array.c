#include "array.h"
#include "math_util.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>


size_t array_size(struct array_t *arr)
{
	return arr->size;
}

size_t array_capacity(struct array_t *arr)
{
	return arr->capacity;
}

struct array_t *make_array(size_t capacity, enum storable_t type)
{
	struct array_t *arr = malloc(sizeof(struct array_t));
	size_t rounded_cap = nearest_power_2(capacity);
	arr->elements = (struct stored_val_t *)malloc(
		sizeof(struct stored_val_t) * rounded_cap);
	return arr;
}

void array_append(struct array_t *arr, struct stored_val_t elem)
{
	size_t size = arr->size;
	size_t capacity = arr->capacity;
	if (capacity - size > 0) {
		// We have enough room to append an element
	} else {
		// Need to allocate more memory for array
		increase_array_capacity(arr);
		arr->elements[size] = elem;
	}
}

struct stored_val_t *array_get(struct array_t *arr, size_t index)
{
	assert(index < arr->size);
	return &arr->elements[index];
}

void increase_array_capacity(struct array_t *arr)
{
	// Get new capacity
	size_t new_cap = arr->capacity * 2;

	// Allocate new space
	struct stored_val_t *new_elements = (struct stored_val_t *)malloc(
		sizeof(struct stored_val_t) * new_cap);
	memcpy(new_elements, arr->elements,
	       arr->size * sizeof(struct stored_val_t));
	arr->elements = new_elements;
}
