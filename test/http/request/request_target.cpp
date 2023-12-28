#include <gtest/gtest.h>

extern "C" {
#include "http/request/request_target.h"
#include "misc/vector/iter.h"
#include "misc/vector/vector.h"
}

TEST(request_target, empty) {
  const char *actual = "";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(request_target_parse(&it), ParseErr);
  ASSERT_EQ(iterVec_peek(&it).ch, '\0');

  vec_free(&vec);
}

TEST(request_target, space) {
  const char *actual = " |";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(request_target_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, ' ');

  vec_free(&vec);
}

TEST(request_target, test) {
  const char *actual = " |";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(request_target_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, ' ');

  vec_free(&vec);
}
