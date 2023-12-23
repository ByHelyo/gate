#include "http/request/unreserved.h"

#include "http/request/misc.h"
#include "misc/vector/iter.h"

int is_unreserved(char ch) {
  return is_alpha(ch) || is_digit(ch) || ch == '-' || ch == '.' || ch == '_' ||
         ch == '~';
}

enum ParseResult unreserved_parse(struct IterVec *http) {
  struct IterResult ret = iterVec_next(http);

  if (ret.status == IterNone || !is_unreserved(ret.ch)) {
    return ParseErr;
  }

  return ParseOk;
}
