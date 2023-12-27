#include "http/request/ipvfuture.h"

#include "http/request/misc.h"
#include "http/request/sub_delims.h"
#include "http/request/unreserved.h"
#include "misc/vector/iter.h"

enum ParseResult ipvfuture_parse(struct IterVec *http) {
  struct IterResult ret = iterVec_next(http);
  unsigned int count = 0;

  if (!ret.status || ret.ch != 'v') {
    return ParseErr;
  }

  while (1) {
    ret = iterVec_peek(http);

    if (!ret.status || !is_hexdig(ret.ch)) {
      break;
    }

    iterVec_next(http);
    ++count;
  }

  if (count == 0) {
    return ParseErr;
  }

  ret = iterVec_next(http);

  if (!ret.status || ret.ch != '.') {
    return ParseErr;
  }

  count = 0;

  while (1) {
    ret = iterVec_peek(http);

    if (!ret.status) {
      break;
    }

    if (is_unreserved(ret.ch)) {
      iterVec_next(http);
    } else if (is_sub_delims(ret.ch)) {
      iterVec_next(http);
    } else if (ret.ch == ':') {
      iterVec_next(http);
    } else {
      break;
    }

    ++count;
  }

  return count > 0 ? ParseOk : ParseErr;
}
