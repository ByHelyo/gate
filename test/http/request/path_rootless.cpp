#include <gtest/gtest.h>

extern "C" {
#include "http/request/path_rootless.h"
#include "misc/vector/iter.h"
#include "misc/vector/vector.h"
}

TEST(path_rootless, empty) {
  const char *actual = "";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(path_rootless_parse(&it), ParseErr);
  ASSERT_EQ(iterVec_peek(&it).ch, '\0');

  vec_free(&vec);
}

TEST(path_rootless, space) {
  const char *actual = " |";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(path_rootless_parse(&it), ParseErr);
  ASSERT_EQ(iterVec_peek(&it).ch, ' ');

  vec_free(&vec);
}

TEST(path_rootless, one) {
  const char *actual = "A|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(path_rootless_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, '|');

  vec_free(&vec);
}

TEST(path_rootless, valid) {
  const char *actual = "A/a/a/a/a|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(path_rootless_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, '|');

  vec_free(&vec);
}
