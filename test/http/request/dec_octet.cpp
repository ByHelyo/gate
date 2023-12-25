#include <gtest/gtest.h>

extern "C" {
#include "http/request/dec_octet.h"
#include "misc/vector/iter.h"
#include "misc/vector/vector.h"
}

TEST(dec_octet, empty) {
  const char *actual = "";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(dec_octet_parse(&it), ParseErr);
  ASSERT_EQ(iterVec_peek(&it).ch, '\0');
}

TEST(dec_octet, space) {
  const char *actual = " |";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(dec_octet_parse(&it), ParseErr);
  ASSERT_EQ(iterVec_peek(&it).ch, ' ');
}

TEST(dec_octet, all) {
  char actual[5];

  for (int i = 0; i < 256; ++i) {
    sprintf(actual, "%i|", i);
    struct Vec vec;
    struct IterVec it;

    vec_init(&vec);
    vec_push_str(&vec, actual, strlen(actual));
    iterVec_init(&it, &vec);

    ASSERT_EQ(dec_octet_parse(&it), ParseOk);
    ASSERT_EQ(iterVec_peek(&it).ch, '|');
  }
}

TEST(dec_octet, take_highest_number) {
  const char *actual = "2551";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(dec_octet_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, '1');
}

TEST(dec_octet, not_a_number) {
  const char *actual = "|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(dec_octet_parse(&it), ParseErr);
  ASSERT_EQ(iterVec_peek(&it).ch, '|');
}