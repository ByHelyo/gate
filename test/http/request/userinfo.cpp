#include <gtest/gtest.h>

extern "C" {
#include "http/request/userinfo.h"
#include "misc/vector/iter.h"
#include "misc/vector/vector.h"
}

TEST(userinfo, empty) {
  const char *actual = "";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(userinfo_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, '\0');
}

TEST(userinfo, space) {
  const char *actual = " |";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(userinfo_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, ' ');
}

TEST(userinfo, unreserved) {
  const char *actual = "helloworld|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(userinfo_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, '|');
}

TEST(userinfo, pct_encoded) {
  const char *actual = "%BE%CD|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(userinfo_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, '|');
}

TEST(userinfo, sub_delims) {
  const char *actual = "(),()|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(userinfo_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, '|');
}

TEST(userinfo, unreserved_with_sub_delims) {
  const char *actual = "h!|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(userinfo_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, '|');
}

TEST(userinfo, unreserved_with_pct_encoded) {
  const char *actual = "!%AF|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(userinfo_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, '|');
}

TEST(userinfo, semi_colon) {
  const char *actual = ":!%AF|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(userinfo_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, '|');
}
