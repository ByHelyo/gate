#include "http/request/hier_part.h"

#include "http/request/authority.h"
#include "misc/vector/iter.h"

enum ParseResult hier_part_parse(struct IterVec *http) {
  struct IterResult ret = iterVec_peek(http);

  if (!ret.status) {
    return ParseOk;
  }

  if (ret.ch == '/') {
    iterVec_next(http);
    ret = iterVec_next(http);

    if (!ret.status) {
      return ParseErr;
    }

    if (ret.ch == '/') {
      iterVec_next(http);
      if (!authority_parse(http)) {
        return ParseErr;
      }
    } else {
      // TODO : path-absolute
    }
  }

  return ParseErr;
}
