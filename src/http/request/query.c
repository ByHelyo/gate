#include "http/request/query.h"
#include "http/request/pchar.h"
#include "misc/vector/iter.h"

enum ParseResult query_parse(struct IterVec *http) {
  while (1) {
    struct IterResult ret = iterVec_peek(http);

    if (ret.status == IterNone || ret.ch == ' ') {
      return ParseOk;
    }

    if (is_pchar(ret.ch)) {
      if (pchar_parse(http) == ParseErr) {
        return ParseErr;
      }
    } else if (ret.ch == '/') {
      iterVec_next(http);
    } else if (ret.ch == '?') {
      iterVec_next(http);
    } else {
      return ParseOk;
    }
  }
}
