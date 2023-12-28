#include "http/request/absolute_uri.h"

#include "http/request/fragment.h"
#include "http/request/hier_part.h"
#include "http/request/query.h"
#include "http/request/scheme.h"
#include "misc/vector/iter.h"

enum ParseResult absolute_uri_parse(struct IterVec *http) {
  if (!scheme_parse(http)) {
    return ParseErr;
  }

  struct IterResult ret = iterVec_next(http);

  if (!ret.status || ret.ch != ':') {
    return ParseErr;
  }

  if (!hier_part_parse(http)) {
    return ParseErr;
  }

  ret = iterVec_peek(http);

  if (!ret.status) {
    return ParseOk;
  }

  if (ret.ch == '?') {
    iterVec_next(http);

    if (!query_parse(http)) {
      return ParseErr;
    }

    ret = iterVec_peek(http);

    if (!ret.status) {
      return ParseOk;
    }
  }

  return ParseOk;
}
