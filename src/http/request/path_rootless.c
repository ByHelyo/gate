#include "http/request/path_rootless.h"

#include "http/request/segment.h"
#include "http/request/segment_nz.h"
#include "misc/vector/iter.h"

enum ParseResult path_rootless_parse(struct IterVec *http) {
  struct IterResult ret;

  if (!segment_nz_parse(http)) {
    return ParseErr;
  }

  while (1) {
    ret = iterVec_peek(http);

    if (!ret.status || ret.ch != '/') {
      return ParseOk;
    }

    iterVec_next(http);

    if (!segment_parse(http)) {
      return ParseErr;
    }
  }
}
