#include <gtest/gtest.h>

extern "C" {
#include "http/request/host.h"
#include "misc/vector/iter.h"
#include "misc/vector/vector.h"
}

TEST(host, empty) {
  const char *actual = "";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(host_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, '\0');

  vec_free(&vec);
}

TEST(host, space) {
  const char *actual = " |";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(host_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, ' ');

  vec_free(&vec);
}

TEST(host, ip_literal) {
  const char *actual = "[::1]|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(host_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, '|');

  vec_free(&vec);
}

TEST(host, ipv4) {
  const char *actual = "1.1.1.1|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(host_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, '|');

  vec_free(&vec);
}

TEST(host, reg_name) {
  const char *actual = "1.].1.1|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(host_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, ']');

  vec_free(&vec);
}
