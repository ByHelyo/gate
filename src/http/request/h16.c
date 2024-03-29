#include "http/request/h16.h"

#include "http/request/misc.h"
#include "misc/vector/iter.h"

enum ParseResult h16_parse(struct IterVec *http) {
  int count = 0;
  for (int i = 0; i < 4; ++i) {
    struct IterResult ret = iterVec_peek(http);

    if (!ret.status || !is_hexdig(ret.ch)) {
      break;
    }

    iterVec_next(http);
    ++count;
  }

  return count > 0 ? ParseOk : ParseErr;
}
