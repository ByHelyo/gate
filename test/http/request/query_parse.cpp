#include <gtest/gtest.h>

extern "C" {
#include "http/request/query.h"
#include "misc/vector/iter.h"
#include "misc/vector/vector.h"
}

TEST(query, empty) {
  const char *actual = "";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(query_parse(&it), ParseOk);
}

TEST(query, space) {
  const char *actual = " |";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(query_parse(&it), ParseOk);
}

TEST(query, invalid) {
  const char *actual = "]|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(query_parse(&it), ParseOk);
}

TEST(query, just_slash) {
  const char *actual = "/|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(query_parse(&it), ParseOk);
}

TEST(query, just_question_mark) {
  const char *actual = "?|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(query_parse(&it), ParseOk);
}

TEST(query, long_valid) {
  const char *actual = "//?//??%3F,,,))(((&&$$$==%AA|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(query_parse(&it), ParseOk);
}

TEST(query, wrong_pct_encoded) {
  const char *actual = "//?//??%3,,,))(((&&$$$==%AA|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(query_parse(&it), ParseErr);
}
