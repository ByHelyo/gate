#include "http/request/segment.h"

#include "http/request/pchar.h"
#include "misc/vector/iter.h"

enum ParseResult segment_parse(struct IterVec *http) {
  while (1) {
    struct IterResult ret = iterVec_peek(http);

    if (ret.status == IterNone) {
      return ParseOk;
    }

    if (!is_pchar(ret.ch)) {
      return ParseOk;
    }

    if (pchar_parse(http) == ParseErr) {
      return ParseErr;
    }
  }
}
