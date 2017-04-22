#ifndef __DATA_H
#define __DATA_H

#include <stdbool.h>

enum data_type {
  undefined_t,
  int_t,
  uint_t,
  long_t,
  ulong_t,
  long_long_t,
  ulong_long_t,
  float_t,
  double_t,
  string_t
};

union data_val {
  int i;
  unsigned int ui;
  long l;
  unsigned long ul;
  long long ll;
  unsigned long long ull;
  float f;
  double d;
  char* s;
};


struct data_t {
  enum data_type type;
  union data_val value;
};

/**
 * Determine whether two @p data_t structs are equivalent
 *
 * @param d1 the first @p data_t struct
 * @param d2 the second @p data_t struct
 *
 * @return @p true if they are the same, @p false otherwise
 */
bool data_t_cmp(struct data_t d1, struct data_t d2) {
  if (d1.type != d2.type || d1.value != d2.value)
    return false;
  return true;
}

#endif // __DATA_H
