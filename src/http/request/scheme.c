#include "http/request/scheme.h"
#include "http/request/misc.h"
#include "misc/vector/iter.h"

enum ParseResult scheme_parse(struct IterVec *http) {
  struct IterResult ret = iterVec_next(http);

  if (ret.status == IterNone || !is_alpha(ret.ch)) {
    return ParseErr;
  }

  iterVec_next(http);
  while (1) {
    ret = iterVec_peek(http);

    if (ret.status == IterNone) {
      return ParseOk;
    }

    if (is_alpha(ret.ch)) {
      iterVec_next(http);
    } else if (is_digit(ret.ch)) {
      iterVec_next(http);
    } else if (ret.ch == '+' || ret.ch == '-' || ret.ch == '.') {
      iterVec_next(http);
    } else {
      return ParseOk;
    }
  }
}
