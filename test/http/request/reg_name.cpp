#include <gtest/gtest.h>

extern "C" {
#include "http/request/reg_name.h"
#include "misc/vector/iter.h"
#include "misc/vector/vector.h"
}

TEST(reg_name, empty) {
  const char *actual = "";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(reg_name_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, '\0');

  vec_free(&vec);
}

TEST(reg_name, space) {
  const char *actual = " |";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(reg_name_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, ' ');

  vec_free(&vec);
}

TEST(reg_name, valid) {
  const char *actual = "333%3F() |";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(reg_name_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, ' ');

  vec_free(&vec);
}

TEST(reg_name, still_valid) {
  const char *actual = "333%3F([) |";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(reg_name_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, '[');

  vec_free(&vec);
}
