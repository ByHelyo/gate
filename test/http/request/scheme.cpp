#include <gtest/gtest.h>

extern "C" {
#include "http/request/scheme.h"
#include "misc/vector/iter.h"
#include "misc/vector/vector.h"
}

TEST(scheme, empty) {
  const char *actual = "";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(scheme_parse(&it), ParseErr);
  ASSERT_EQ(iterVec_peek(&it).ch, '\0');
}

TEST(scheme, space) {
  const char *actual = " |";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(scheme_parse(&it), ParseErr);
  ASSERT_EQ(iterVec_peek(&it).ch, '|');
}

TEST(scheme, valid) {
  const char *actual = "HelloWorld|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(scheme_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, '|');
}

TEST(scheme, valid_followed_with_characters) {
  const char *actual = "HelloWorld|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(scheme_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, '|');
}

TEST(scheme, long_valid) {
  const char *actual = "He+...+---ll++--..oWorld..|..";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(scheme_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, '|');
}

TEST(scheme, invalid) {
  const char *actual = "|e+...+---ll++--..oWorld..|..";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(scheme_parse(&it), ParseErr);
  ASSERT_EQ(iterVec_peek(&it).ch, 'e');
}

TEST(scheme, short_valid) {
  const char *actual = "g";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(scheme_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, '\0');
}

TEST(scheme, short_invalid) {
  const char *actual = "3";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(scheme_parse(&it), ParseErr);
  ASSERT_EQ(iterVec_peek(&it).ch, '\0');
}
