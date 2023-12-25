#include <gtest/gtest.h>

extern "C" {
#include "http/request/absolute_path.h"
#include "misc/vector/iter.h"
#include "misc/vector/vector.h"
}

TEST(absolute_path, empty) {
  const char *actual = "";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(absolute_path_parse(&it), ParseErr);
  ASSERT_EQ(iterVec_peek(&it).ch, '\0');
}

TEST(absolute_path, space) {
  const char *actual = " |";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(absolute_path_parse(&it), ParseErr);
  ASSERT_EQ(iterVec_peek(&it).ch, ' ');
}

TEST(absolute_path, invalid) {
  const char *actual = "|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(absolute_path_parse(&it), ParseErr);
  ASSERT_EQ(iterVec_peek(&it).ch, '|');
}

TEST(absolute_path, simple_valid) {
  const char *actual = "/C |";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(absolute_path_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, ' ');
}

TEST(absolute_path, slash) {
  const char *actual = "/ |";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(absolute_path_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, ' ');
}

TEST(absolute_path, double_slash) {
  const char *actual = "// |";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(absolute_path_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, ' ');
}

TEST(absolute_path, valid) {
  const char *actual = "/('%1A'Helloworld!') |";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(absolute_path_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, ' ');
}

TEST(absolute_path, long_valid) {
  const char *actual = "/('%1A'Helloworld!')/%AA/,,,%DA |";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(absolute_path_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, ' ');
}
