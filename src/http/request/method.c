#include "http/request/method.h"

#include "misc/vector/iter.h"

enum ParseResult method_parse(struct IterVec *http) {
  struct IterResult ret = iter_vec_peek(http);
  if (ret.status == IterErr) {
    return ParseErr;
  }

  return ParseOk;
}
