#include <gtest/gtest.h>

extern "C" {
#include "http/request/segment.h"
#include "misc/vector/iter.h"
#include "misc/vector/vector.h"
}

TEST(segment, empty) {
  const char *actual = "";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(segment_parse(&it), ParseOk);
}

TEST(segment, space) {
  const char *actual = " |";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(segment_parse(&it), ParseOk);
}

TEST(segment, valid) {
  const char *actual = "('%FFF') |";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(segment_parse(&it), ParseOk);
}

TEST(segment, nothing) {
  const char *actual = "] |";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(segment_parse(&it), ParseOk);
}

TEST(segment, long_segment) {
  const char *actual = "%33,helloworld!(%FA%3F)) |";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(segment_parse(&it), ParseOk);
}

TEST(segment, pct_encoded_unfinished) {
  const char *actual = "%3 |";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(segment_parse(&it), ParseErr);
}

TEST(segment, long_segment_pct_unfinished) {
  const char *actual = "%33,helloworld!(%FG)) |";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(segment_parse(&it), ParseErr);
}
