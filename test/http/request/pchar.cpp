#include <gtest/gtest.h>

extern "C" {
#include "http/request/pchar.h"
#include "misc/vector/iter.h"
#include "misc/vector/vector.h"
}

TEST(pchar, empty) {
  const char *actual = "";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(pchar_parse(&it), ParseErr);
}

TEST(pchar, space) {
  const char *actual = " -";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(pchar_parse(&it), ParseErr);
}

TEST(pchar, unreserved) {
  const char *actual = "3-";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(pchar_parse(&it), ParseOk);
}

TEST(pchar, pct_encoded) {
  const char *actual = "%A3-";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(pchar_parse(&it), ParseOk);
}

TEST(pchar, sub_delims) {
  const char *actual = "'-";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(pchar_parse(&it), ParseOk);
}

TEST(pchar, square_close_bracket) {
  const char *actual = "]-";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(pchar_parse(&it), ParseErr);
}
