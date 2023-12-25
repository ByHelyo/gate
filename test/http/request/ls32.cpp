#include <gtest/gtest.h>

extern "C" {
#include "http/request/ls32.h"
#include "misc/vector/iter.h"
#include "misc/vector/vector.h"
}

TEST(ls32, empty) {
  const char *actual = "";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(ls32_parse(&it), ParseErr);
  ASSERT_EQ(iterVec_peek(&it).ch, '\0');
}

TEST(ls32, space) {
  const char *actual = " |";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(ls32_parse(&it), ParseErr);
  ASSERT_EQ(iterVec_peek(&it).ch, ' ');
}

TEST(ls32, valid_not_ipv4) {
  const char *actual = "A:ABCD |";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(ls32_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, ' ');
}

TEST(ls32, valid_short_not_ipv4) {
  const char *actual = "A:A |";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(ls32_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, ' ');
}

TEST(ls32, valid_long_not_ipv4) {
  const char *actual = "AAAA:FFFF |";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(ls32_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, ' ');
}

TEST(ls32, valid_ipv4) {
  const char *actual = "127.0.0.1 |";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(ls32_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, ' ');
}

TEST(ls32, mix) {
  const char *actual = "127:0.0.1 |";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(ls32_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, '.');
}

TEST(ls32, mix_invalid) {
  const char *actual = "127:G.0.1 |";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(ls32_parse(&it), ParseErr);
  ASSERT_EQ(iterVec_peek(&it).ch, 'G');
}
