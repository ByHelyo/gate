#include <gtest/gtest.h>

extern "C" {
#include "http/request/unreserved.h"
#include "misc/vector/iter.h"
#include "misc/vector/vector.h"
}

TEST(unreserved, empty) {
  const char *actual = "";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(unreserved_parse(&it), ParseErr);
}

TEST(unreserved, space) {
  const char *actual = " |";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(unreserved_parse(&it), ParseErr);
}

TEST(unreserved, dash) {
  const char *actual = "- ";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(unreserved_parse(&it), ParseOk);
}

TEST(unreserved, dot) {
  const char *actual = ". ";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(unreserved_parse(&it), ParseOk);
}

TEST(unreserved, underscore) {
  const char *actual = "_ ";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(unreserved_parse(&it), ParseOk);
}

TEST(unreserved, wave) {
  const char *actual = "~ ";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(unreserved_parse(&it), ParseOk);
}

TEST(unreserved, alpha_lower) {
  const char *actual = "c|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(unreserved_parse(&it), ParseOk);
}

TEST(unreserved, alpha_upper) {
  const char *actual = "G|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(unreserved_parse(&it), ParseOk);
}

TEST(unreserved, digit_min) {
  const char *actual = "0|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(unreserved_parse(&it), ParseOk);
}

TEST(unreserved, digit_max) {
  const char *actual = "9|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(unreserved_parse(&it), ParseOk);
}

TEST(unreserved, alpha_upper_min) {
  const char *actual = "A|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(unreserved_parse(&it), ParseOk);
}

TEST(unreserved, alpha_upper_max) {
  const char *actual = "Z|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(unreserved_parse(&it), ParseOk);
}

TEST(unreserved, alpha_lower_min) {
  const char *actual = "a|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(unreserved_parse(&it), ParseOk);
}

TEST(unreserved, alpha_lower_max) {
  const char *actual = "z|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(unreserved_parse(&it), ParseOk);
}
