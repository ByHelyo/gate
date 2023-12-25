#include <gtest/gtest.h>

extern "C" {
#include "http/request/ipv4address.h"
#include "misc/vector/iter.h"
#include "misc/vector/vector.h"
}

TEST(ipv4address, empty) {
  const char *actual = "";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(ipv4address_parse(&it), ParseErr);
  ASSERT_EQ(iterVec_peek(&it).ch, '\0');
}

TEST(ipv4address, space) {
  const char *actual = " |";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(ipv4address_parse(&it), ParseErr);
  ASSERT_EQ(iterVec_peek(&it).ch, ' ');
}

TEST(ipv4address, valid) {
  const char *actual = "1.1.1.1|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(ipv4address_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, '|');
}

TEST(ipv4address, localhost) {
  const char *actual = "127.0.0.1|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(ipv4address_parse(&it), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, '|');
}

TEST(ipv4address, not_dec_octet) {
  const char *actual = "1271.0.0.1|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(ipv4address_parse(&it), ParseErr);
  ASSERT_EQ(iterVec_peek(&it).ch, '.');
  ASSERT_EQ(iterVec_nth(&it, 3).ch, '0');
}

TEST(ipv4address, invalid) {
  const char *actual = "127.0.,0.1|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(ipv4address_parse(&it), ParseErr);
  ASSERT_EQ(iterVec_peek(&it).ch, ',');
}

TEST(ipv4address, comma) {
  const char *actual = "127.0,0.1|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(ipv4address_parse(&it), ParseErr);
  ASSERT_EQ(iterVec_peek(&it).ch, '0');
}

TEST(ipv4address, hex) {
  const char *actual = "127.0.A.1|";
  struct Vec vec;
  struct IterVec it;

  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(ipv4address_parse(&it), ParseErr);
  ASSERT_EQ(iterVec_peek(&it).ch, 'A');
}
