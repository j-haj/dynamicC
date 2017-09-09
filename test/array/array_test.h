#include "array.h"

#include "gtest/gtest.h"

TEST(ArrayTest, InitializeTest) {
  struct array_t* array = make_array(5, int_t);
  ASSERT_TRUE(array != NULL);
}

TEST(ArrayTest, SizeTest) {
  struct array_t* array = make_array(5, int_t);
  size_t actual_size = array_size(array);
  size_t expected_size = 0;
  ASSERT_TRUE(actual_size == expected_size);
}

TEST(ArrayTest, CapacityTest) {
  struct array_t* array = make_array(1, int_t);
  size_t actual_capacity = array_capacity(array);
  size_t expected_capacity = 2;
  ASSERT_TRUE(actual_capacity == expected_capacity);
}
