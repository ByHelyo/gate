#include <gtest/gtest.h>

extern "C" {
#include <misc/vector/vector.h>
}

TEST(vector, build_vector) {
  struct Vec vec;

  vec_init(&vec);

  ASSERT_EQ(vec.size, 0);
  ASSERT_EQ(vec.capacity, 0);

  vec_free(&vec);
}


TEST(vector, clear_vector) {
  struct Vec vec;

  vec_init(&vec);
  vec_free(&vec);

  ASSERT_EQ(vec.capacity, 0);
  ASSERT_EQ(vec.size, 0);
}

TEST(vector, vector_push_one_element) {
  struct Vec vec;
  char elt = 'g';

  vec_init(&vec);
  ASSERT_EQ(vec_push(&vec, elt), 0);

  ASSERT_EQ(vec.size, 1);
  ASSERT_EQ(vec.capacity, 8);
  ASSERT_EQ(elt, vec.data[0]);

  vec_free(&vec);
}

TEST(vector, vector_fill_capacity) {
    struct Vec vec;
    char elt_1 = 'v';
    char elt_2 = 'o';
    char elt_3 = 'a';
    char elt_4 = 'f';
    char elt_5 = 'c';
    char elt_6 = 'd';
    char elt_7 = 't';
    char elt_8 = 'e';

    vec_init(&vec);

  ASSERT_EQ(vec_push(&vec, elt_1), 0);
    ASSERT_EQ(vec_push(&vec, elt_2), 0);
    ASSERT_EQ(vec_push(&vec, elt_3), 0);
    ASSERT_EQ(vec_push(&vec, elt_4), 0);
    ASSERT_EQ(vec_push(&vec, elt_5), 0);
    ASSERT_EQ(vec_push(&vec, elt_6), 0);
    ASSERT_EQ(vec_push(&vec, elt_7), 0);
    ASSERT_EQ(vec_push(&vec, elt_8), 0);

    ASSERT_EQ(vec.size, 8);
    ASSERT_EQ(vec.capacity, 8);
    ASSERT_EQ(elt_1, vec.data[0]);
    ASSERT_EQ(elt_2, vec.data[1]);
    ASSERT_EQ(elt_3, vec.data[2]);
    ASSERT_EQ(elt_4, vec.data[3]);
    ASSERT_EQ(elt_5, vec.data[4]);
    ASSERT_EQ(elt_6, vec.data[5]);
    ASSERT_EQ(elt_7, vec.data[6]);
    ASSERT_EQ(elt_8, vec.data[7]);

    vec_free(&vec);
}

TEST(vector, vector_fill_to_grow) {
  struct Vec vec;
  char elt_1 = 'v';
  char elt_2 = 'o';
  char elt_3 = 'a';
  char elt_4 = 'f';
  char elt_5 = 'c';
  char elt_6 = 'd';
  char elt_7 = 't';
  char elt_8 = 'e';
  char elt_9 = 'p';

  vec_init(&vec);

  ASSERT_EQ(vec_push(&vec, elt_1), 0);
  ASSERT_EQ(vec_push(&vec, elt_2), 0);
  ASSERT_EQ(vec_push(&vec, elt_3), 0);
  ASSERT_EQ(vec_push(&vec, elt_4), 0);
  ASSERT_EQ(vec_push(&vec, elt_5), 0);
  ASSERT_EQ(vec_push(&vec, elt_6), 0);
  ASSERT_EQ(vec_push(&vec, elt_7), 0);
  ASSERT_EQ(vec_push(&vec, elt_8), 0);
  ASSERT_EQ(vec_push(&vec, elt_9), 0);

  ASSERT_EQ(vec.size, 9);
  ASSERT_EQ(vec.capacity, 16);
  ASSERT_EQ(elt_1, vec.data[0]);
  ASSERT_EQ(elt_2, vec.data[1]);
  ASSERT_EQ(elt_3, vec.data[2]);
  ASSERT_EQ(elt_4, vec.data[3]);
  ASSERT_EQ(elt_5, vec.data[4]);
  ASSERT_EQ(elt_6, vec.data[5]);
  ASSERT_EQ(elt_7, vec.data[6]);
  ASSERT_EQ(elt_8, vec.data[7]);
  ASSERT_EQ(elt_9, vec.data[8]);

  vec_free(&vec);
}

TEST(vector, vector_push_str_to_fill_no_grow) {
  struct Vec vec;
  char expected[] = "Password";

  vec_init(&vec);
  ASSERT_EQ(vec_push_str(&vec, expected, strlen(expected)), 0);

  ASSERT_EQ(vec.size, 8);
  ASSERT_EQ(vec.capacity, 8);
  ASSERT_EQ(strncmp(expected, vec.data, 8), 0);

  vec_free(&vec);
}

TEST(vector, vector_push_str_to_grow) {
  struct Vec vec;
  char expected[] = "Technique";

  vec_init(&vec);
  ASSERT_EQ(vec_push_str(&vec, expected, strlen(expected)), 0);

  ASSERT_EQ(vec.size, strlen(expected));
  ASSERT_EQ(vec.capacity, 16);
  ASSERT_EQ(strncmp(expected, vec.data, strlen(expected)), 0);

  vec_free(&vec);
}

TEST(vector, vector_push_long_str) {
  struct Vec vec;
  char expected[] = "enim lobortis scelerisque fermentum dui faucibus in ornare quam viverra orci sagittis eu volutpat odio facilisis mauris sit amet massa vitae tortor condimentum lacinia quis vel eros donec ac odio tempor orci dapibus ultrices in iaculis nunc sed augue lacus viverra vitae congue eu consequat ac felis donec et odio pellentesque diam volutpat commodo sed egestas egestas fringilla phasellus faucibus scelerisque eleifend donec pretium vulputate sapien nec sagittis aliquam malesuada bibendum arcu vitae elementum curabitur vitae nunc sed velit dignissim sodales ut eu sem integer vitae justo eget magna fermentum iaculis eu non diam phasellus vestibulum lorem sed risus ultricies";

  vec_init(&vec);
  ASSERT_EQ(vec_push_str(&vec, expected, strlen(expected)), 0);

  ASSERT_EQ(vec.size, strlen(expected));
  ASSERT_EQ(vec.capacity, 1024);
  ASSERT_EQ(strncmp(expected, vec.data, strlen(expected)), 0);

  vec_free(&vec);
}
