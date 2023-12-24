#include "http/request/pct_encoded.h"

#include "http/request/misc.h"
#include "misc/vector/iter.h"

int is_pct_encoded(char ch) { return ch == '%'; }

enum ParseResult pct_encoded_parse(struct IterVec *http) {
  struct IterResult ret = iterVec_next(http);

  if (!ret.status || !is_pct_encoded(ret.ch)) {
    return ParseErr;
  }

  for (int i = 0; i < 2; ++i) {
    ret = iterVec_next(http);

    if (!ret.status || !is_hexdig(ret.ch)) {
      return ParseErr;
    }
  }

  return ParseOk;
}
