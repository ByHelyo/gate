#include <gtest/gtest.h>

extern "C" {
#include "http/request/pct_encoded.h"
#include "misc/vector/iter.h"
#include "misc/vector/vector.h"
}

TEST(pct_encoded, empty) {
  const char *actual = "";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(pct_encoded_parse(&it), ParseErr);
  ASSERT_EQ(iterVec_peek(&it).ch, '\0');
}

TEST(pct_encoded, space) {
  const char *actual = " |";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(pct_encoded_parse(&it), ParseErr);
  ASSERT_EQ(iterVec_peek(&it).ch, '|');
}

TEST(pct_encoded, hex) {
  const char *actual = "%3F|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(pct_encoded_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, '|');
}

TEST(pct_encoded, digit) {
  const char *actual = "%33|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(pct_encoded_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, '|');
}

TEST(pct_encoded, hex_min) {
  const char *actual = "%00|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(pct_encoded_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, '|');
}

TEST(pct_encoded, hex_max) {
  const char *actual = "%FF|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(pct_encoded_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, '|');
}

TEST(pct_encoded, not_hex) {
  const char *actual = "%FG|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(pct_encoded_parse(&it), ParseErr);
  ASSERT_EQ(iterVec_peek(&it).ch, '|');
}

TEST(pct_encoded, unfinished_hex) {
  const char *actual = "%F|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(pct_encoded_parse(&it), ParseErr);
  ASSERT_EQ(iterVec_peek(&it).ch, '\0');
}

TEST(pct_encoded, no_percent) {
  const char *actual = "AF|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(pct_encoded_parse(&it), ParseErr);
  ASSERT_EQ(iterVec_peek(&it).ch, 'F');
}

TEST(pct_encoded, invalid) {
  const char *actual = "|||";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(pct_encoded_parse(&it), ParseErr);
  ASSERT_EQ(iterVec_peek(&it).ch, '|');
}
