#ifndef ARRAY_H_
#define ARRAY_H_

#include <stdlib.h>

enum storable_t {
  undef_t,
  int_t,
  long_t,
  uint_t,
  ulong_t,
  double_t,
  float_t,
  string_t,
  byte_t
};

struct stored_val_t {
  enum storable_t t;

  union {
    int i;
    long l;
    unsigned int ui;
    unsigned long ul;
    double d;
    float f;
    char* s;
    char b;
  } value;
};

/** Array type
 *
 * Arrays are containers that can store elements of ``struct stored_val_t``.
 * This is to try and keep the array container generic, without having to use
 * ``void *`` and casting tricks.
 *
 * Arrays have both ``size`` and ``capacity``, where ``size`` describes the
 * number of elements currently stored in the array, and ``capacity`` describes
 * the total number of elements that can be stored in the array before more
 * memory will be allocated. As an example, an array could have a ``capacity``
 * of 4, meaning it could store a total of 4 elements, and only using half of
 * that storage by storing 2 elements and thus having ``size`` 2. If 3 more
 * elements were appended to the array, a space allocation would take place
 * along with a copy, doubling the size of the array.
 */
struct array_t {
  size_t size;      // Default size is 1
  size_t capacity;  // Default capacity is 1
  struct stored_val_t* elements;
};

/**
 * Gets the size of the array
 *
 * The size of the array is the number of elements currently stored in the
 * array. This is commonly referred to as the length of the array.
 *
 * @param arr array whose size is to be determined
 *
 * @return size of the array
 */
size_t array_size(struct array_t* arr);

/**
 * Gets the capacity of the array.
 *
 * The capacity of the array is the number of elements that can be added to the
 * array before additional memory is allocated.
 *
 * @param arr the array whose capacity is to be determined
 *
 * @return the capacity of the array
 */
size_t array_capacity(struct array_t* arr);

/**
 * Appends an element to the given array
 *
 * @param arr the array to be appended to
 * @param elem the element being appended to the array
 */
void array_append(struct array_t* arr, struct stored_val_t elem);

/**
 * Sets the value of the array for the given index
 *
 * @param arr array whose `index`th element is being updated
 * @param index the index of the element to be updated
 * @param elem the element being used to update the array
 */
void array_set(struct array_t* arr, long index, struct stored_val_t* elem);

/**
 * Retrieves the value stored at `index`
 *
 * @param arr array being accessed
 * @param index the index of the element being requested
 *
 * @return The `struct stored_val_t*` being stored at `index`
 */
struct stored_val_t* array_get(struct array_t* arr, size_t index);

/**
 * Create an array on the heap with specified capacity. The array will be
 * created to the nearest multiple of 2 to ``capacity``, rounded up
 *
 * @param capacity Desired capacity of the array
 */
struct array_t* make_array(size_t capacity, enum storable_t type);

/**
 * Doubles the internal capacity of the array and copies the elements over to
 * the newly allocated memory.
 *
 * @param arr pointer to array struct
 *
 * @return pointer to array with double the capacity of the original array
 */
void increase_array_capacity(struct array_t* arr);

#endif  // ARRAY_H_
