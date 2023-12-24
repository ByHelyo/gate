#include "http/request/hier_part.h"
#include "http/request/segment.h"
#include "misc/vector/iter.h"

enum ParseResult hier_part_parse(struct IterVec *http) {
  struct IterResult ret = iterVec_peek(http);

  if (ret.status == IterNone) {
    return ParseOk;
  }

  if (ret.ch == '/') {
    iterVec_next(http);
    ret = iterVec_next(http);

    if (ret.status == IterNone) {
      return ParseErr;
    }

    if (ret.ch == '/') {
      iterVec_next(http);
      // TODO : path-abempty
    } else {
      // TODO : path-absolute
    }
  }

  return ParseErr;
}
