#include <gtest/gtest.h>

extern "C" {
#include <misc/vector/vector.h>
}

TEST(vector, build_vector_of_int) {
  struct Vec vec;
  vec_build(&vec);

  vec.data[0] = NULL;
  vec.data[1] = NULL;

  ASSERT_EQ(vec.size, 0);
  ASSERT_EQ(vec.capacity, 2);

  vec_destroy(&vec, NULL);
}

TEST(vector, build_vector_of_double) {
  struct Vec vec;
  vec_build(&vec);

  vec.data[0] = NULL;
  vec.data[1] = NULL;

  ASSERT_EQ(vec.size, 0);
  ASSERT_EQ(vec.capacity, 2);

  vec_destroy(&vec, NULL);
}

TEST(vector, vector_push) {
  struct Vec vec;
  int elt = 13;

  vec_build(&vec);
  vec_push(&vec, &elt);


  ASSERT_EQ(vec.size, 1);
  ASSERT_EQ(vec.capacity, 2);
  int *actual_elt = (int *) vec.data[0];
  ASSERT_EQ(elt, *actual_elt);

  vec_destroy(&vec, NULL);
}
