#include "http/request/request.h"
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
  struct Request req;

  req.method = GET;
  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(request_target_parse(&it, &req), ParseErr);
  ASSERT_EQ(iterVec_peek(&it).ch, '\0');

  vec_free(&vec);
}

TEST(request_target, space) {
  const char *actual = " |";
  struct Vec vec;
  struct IterVec it;
  struct Request req;

  req.method = GET;
  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(request_target_parse(&it, &req), ParseErr);
  ASSERT_EQ(iterVec_peek(&it).ch, '|');

  vec_free(&vec);
}

TEST(request_target, origin_form) {
  const char *actual = "/1/1/1/1 |";
  struct Vec vec;
  struct IterVec it;
  struct Request req;

  req.method = GET;
  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(request_target_parse(&it, &req), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, ' ');

  vec_free(&vec);
}

TEST(request_target, origin_form_2) {
  const char *actual = "/where?q=now |";
  struct Vec vec;
  struct IterVec it;
  struct Request req;

  req.method = GET;
  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(request_target_parse(&it, &req), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, ' ');

  vec_free(&vec);
}

TEST(request_target, absolute_form) {
  const char *actual = "http://example:8042/over/there?name=ferret |";
  struct Vec vec;
  struct IterVec it;
  struct Request req;

  req.method = GET;
  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(request_target_parse(&it, &req), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, ' ');

  vec_free(&vec);
}

TEST(request_target, absolute_form_2) {
  const char *actual = "http://www.example.org/pub/WWW/TheProject.html |";
  struct Vec vec;
  struct IterVec it;
  struct Request req;

  req.method = GET;
  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(request_target_parse(&it, &req), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, ' ');

  vec_free(&vec);
}

TEST(request_target, authority_form) {
  const char *actual = "www.example.com:80 |";
  struct Vec vec;
  struct IterVec it;
  struct Request req;

  req.method = CONNECT;
  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(request_target_parse(&it, &req), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, ' ');

  vec_free(&vec);
}

TEST(request_target, asterik_form) {
  const char *actual = "* |";
  struct Vec vec;
  struct IterVec it;

  struct Request req;

  req.method = OPTIONS;
  vec_init(&vec);
  vec_push_str(&vec, actual, strlen(actual));
  iterVec_init(&it, &vec);

  ASSERT_EQ(request_target_parse(&it, &req), ParseOk);
  ASSERT_EQ(iterVec_peek(&it).ch, ' ');

  vec_free(&vec);
}
