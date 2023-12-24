#include "http/request/absolute_path.h"

#include "http/request/segment.h"
#include "misc/vector/iter.h"

enum ParseResult absolute_path_parse(struct IterVec *http) {
  unsigned int count = 0;

  while (1) {
    struct IterResult ret = iterVec_peek(http);

    if (!ret.status || ret.ch != '/') {
      break;
    }

    iterVec_next(http);
    if (!segment_parse(http)) {
      return ParseErr;
    }

    ++count;
  }

  return count >= 1 ? ParseOk : ParseErr;
}
