#include <gtest/gtest.h>

extern "C" {
#include "http/request/fragment.h"
#include "misc/vector/iter.h"
#include "misc/vector/vector.h"
}

TEST(fragment, empty) {
  const char *actual = "";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(fragment_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, '\0');

  vec_free(&vec);
}

TEST(fragment, space) {
  const char *actual = " |";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(fragment_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, ' ');

  vec_free(&vec);
}

TEST(fragment, question_marks) {
  const char *actual = "?????|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(fragment_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, '|');

  vec_free(&vec);
}

TEST(fragment, slashes) {
  const char *actual = "/////|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(fragment_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, '|');

  vec_free(&vec);
}

TEST(fragment, valid) {
  const char *actual = "/////333%3F//??|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(fragment_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, '|');

  vec_free(&vec);
}
