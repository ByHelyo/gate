#include <gtest/gtest.h>

extern "C" {
#include "http/request/origin_form.h"
#include "misc/vector/iter.h"
#include "misc/vector/vector.h"
}

TEST(origin_form, empty) {
  const char *actual = "";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(origin_form_parse(&it), ParseErr);
  ASSERT_EQ(iterVec_peek(&it).ch, '\0');
}

TEST(origin_form, space) {
  const char *actual = " |";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(origin_form_parse(&it), ParseErr);
  ASSERT_EQ(iterVec_peek(&it).ch, ' ');
}

TEST(origin_form, no_query) {
  const char *actual = "/where";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(origin_form_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, '\0');
}

TEST(origin_form, no_query_followed_with_characters) {
  const char *actual = "/where|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(origin_form_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, '|');
}

TEST(origin_form, with_query) {
  const char *actual = "/where?q=now";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(origin_form_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, '\0');
}

TEST(origin_form, invalid) {
  const char *actual = "|/where?q=now";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(origin_form_parse(&it), ParseErr);
  ASSERT_EQ(iterVec_peek(&it).ch, '|');
}
