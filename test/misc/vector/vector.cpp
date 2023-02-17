#include <gtest/gtest.h>

extern "C" {
#include <misc/vector/vector.h>
}

TEST(vector, build_vector) {
  struct Vec vec;

  ASSERT_EQ(vec_build(&vec), 1);

  ASSERT_EQ(vec.size, 0);
  ASSERT_EQ(vec.capacity, 2);

  vec_destroy(&vec, NULL);
}

TEST(vector, vector_push_one_element) {
  struct Vec vec;
  int elt = 13;

  ASSERT_EQ(vec_build(&vec), 1);
  ASSERT_EQ(vec_push(&vec, &elt), 1);

  ASSERT_EQ(vec.size, 1);
  ASSERT_EQ(vec.capacity, 2);
  ASSERT_EQ(elt, *((int *) vec.data[0]));

  vec_destroy(&vec, NULL);
}

TEST(vector, vector_push_elements_to_expand) {
  struct Vec vec;
  int elt_1 = 17;
  int elt_2 = 47;
  int elt_3 = 83;

  ASSERT_EQ(vec_build(&vec), 1);
  ASSERT_EQ(vec_push(&vec, &elt_1), 1);
  ASSERT_EQ(vec_push(&vec, &elt_2), 1);
  ASSERT_EQ(vec_push(&vec, &elt_3), 1);

  ASSERT_EQ(vec.size, 3);
  ASSERT_EQ(vec.capacity, 4);
  ASSERT_EQ(elt_1, *((int *) vec.data[0]));
  ASSERT_EQ(elt_2, *((int *) vec.data[1]));
  ASSERT_EQ(elt_3, *((int *) vec.data[2]));

  vec_destroy(&vec, NULL);
}

TEST(vector, vector_push_elements_to_expand_2) {
    struct Vec vec;
    int elt_1 = 17;
    int elt_2 = 47;
    int elt_3 = 83;
    int elt_4 = 112;
    int elt_5 = 530;
    int elt_6 = 12340;

    ASSERT_EQ(vec_build(&vec), 1);
    ASSERT_EQ(vec_push(&vec, &elt_1), 1);
    ASSERT_EQ(vec_push(&vec, &elt_2), 1);
    ASSERT_EQ(vec_push(&vec, &elt_3), 1);
    ASSERT_EQ(vec_push(&vec, &elt_4), 1);
    ASSERT_EQ(vec_push(&vec, &elt_5), 1);
    ASSERT_EQ(vec_push(&vec, &elt_6), 1);

    ASSERT_EQ(vec.size, 6);
    ASSERT_EQ(vec.capacity, 8);
    ASSERT_EQ(elt_1, *((int *) vec.data[0]));
    ASSERT_EQ(elt_2, *((int *) vec.data[1]));
    ASSERT_EQ(elt_3, *((int *) vec.data[2]));
    ASSERT_EQ(elt_4, *((int *) vec.data[3]));
    ASSERT_EQ(elt_5, *((int *) vec.data[4]));
    ASSERT_EQ(elt_6, *((int *) vec.data[5]));

    vec_destroy(&vec, NULL);
  }
