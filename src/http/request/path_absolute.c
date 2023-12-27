#include "http/request/path_absolute.h"
#include "http/request/pchar.h"
#include "http/request/segment.h"
#include "http/request/segment_nz.h"
#include "misc/vector/iter.h"

enum ParseResult path_absolute_parse(struct IterVec *http) {
  struct IterResult ret = iterVec_next(http);

  if (!ret.status || ret.ch != '/') {
    return ParseErr;
  }

  ret = iterVec_peek(http);

  if (!ret.status || !is_pchar(ret.ch)) {
    return ParseOk;
  }

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
