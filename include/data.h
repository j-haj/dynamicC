#ifndef __DATA_H
#define __DATA_H

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

#endif // __DATA_H
