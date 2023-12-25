#include <gtest/gtest.h>

extern "C" {
#include "http/request/h16.h"
#include "misc/vector/iter.h"
#include "misc/vector/vector.h"
}

TEST(h16, empty) {
  const char *actual = "";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(h16_parse(&it), ParseErr);
}

TEST(h16, space) {
  const char *actual = " |";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(h16_parse(&it), ParseErr);
}

TEST(h16, one_hexdig) {
  const char *actual = "3 |";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(h16_parse(&it), ParseOk);
}

TEST(h16, valid) {
  const char *actual = "3A |";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(h16_parse(&it), ParseOk);
}

TEST(h16, valid_full) {
  const char *actual = "3AFC |";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(h16_parse(&it), ParseOk);
}

TEST(h16, long_hexdig) {
  const char *actual = "3ABCDE |";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(h16_parse(&it), ParseOk);
}
