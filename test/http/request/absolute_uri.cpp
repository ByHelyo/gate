#include <gtest/gtest.h>

extern "C" {
#include "http/request/absolute_uri.h"
#include "misc/vector/iter.h"
#include "misc/vector/vector.h"
}

TEST(absolute_uri, empty) {
  const char *actual = "";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(absolute_uri_parse(&it), ParseErr);
  ASSERT_EQ(iterVec_peek(&it).ch, '\0');

  vec_free(&vec);
}

TEST(absolute_uri, space) {
  const char *actual = " |";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(absolute_uri_parse(&it), ParseErr);
  ASSERT_EQ(iterVec_peek(&it).ch, '|');

  vec_free(&vec);
}

TEST(absolute_uri, only_scheme) {
  const char *actual = "http:|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(absolute_uri_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, '|');

  vec_free(&vec);
}

TEST(absolute_uri, query) {
  const char *actual = "http:localhost?query|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(absolute_uri_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, '|');

  vec_free(&vec);
}
