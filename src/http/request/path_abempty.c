#include "http/request/path_abempty.h"

#include "http/request/segment.h"
#include "misc/vector/iter.h"

enum ParseResult path_abempty_parse(struct IterVec *http) {
  while (1) {
    struct IterResult ret = iterVec_peek(http);

    if (!ret.status || ret.ch != '/') {
      return ParseOk;
    }

    iterVec_next(http);

    if (!segment_parse(http)) {
      return ParseErr;
    }
  }
}
