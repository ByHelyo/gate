#include <gtest/gtest.h>

extern "C" {
#include "http/request/ipv6address.h"
#include "misc/vector/iter.h"
#include "misc/vector/vector.h"
}

TEST(ipv6address, empty) {
  const char *actual = "";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(ipv6address_parse(&it), ParseErr);
  ASSERT_EQ(iterVec_peek(&it).ch, '\0');
}

TEST(ipv6address, space) {
  const char *actual = " |";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(ipv6address_parse(&it), ParseErr);
  ASSERT_EQ(iterVec_peek(&it).ch, ' ');
}

TEST(ipv6address, full_ipv6) {
  const char *actual = "2001:0db8:85a3:0000:0000:8a2e:0370:7334|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(ipv6address_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, '|');
}
