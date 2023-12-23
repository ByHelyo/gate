#include "http/request/absolute_path.h"

#include "http/request/segment.h"
#include "misc/vector/iter.h"

enum ParseResult absolute_path_parse(struct IterVec *http) {
  unsigned int count = 0;

  while (1) {
    struct IterResult ret = iterVec_next(http);

    if (ret.status == IterNone) {
      break;
    }

    if (ret.ch != '/') {
      return ParseErr;
    }

    segment_parse(http);

    ++count;
  }

  return count > 1 ? ParseOk : ParseErr;
}
