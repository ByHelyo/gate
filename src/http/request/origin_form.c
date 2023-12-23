#include "http/request/absolute_path.h"

#include "http/request/origin_form.h"
#include "http/request/query.h"
#include "misc/vector/iter.h"

enum ParseResult origin_form_parse(struct IterVec *http) {
  if (absolute_path_parse(http)) {
    return ParseErr;
  }

  struct IterResult ret = iterVec_peek(http);

  if (ret.status == IterNone) {
    return ParseOk;
  }

  if (ret.ch != '?') {
    return ParseErr;
  }

  if (query_parse(http) == ParseErr) {
    return ParseErr;
  }

  return ParseOk;
}
