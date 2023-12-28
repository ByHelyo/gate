#include "http/request/asterik_form.h"
#include "misc/vector/iter.h"

enum ParseResult asterik_form_parse(struct IterVec *http) {
  struct IterResult ret = iterVec_next(http);

  if (!ret.status || ret.ch != '*') {
    return ParseErr;
  }

  iterVec_next(http);

  return ParseOk;
}
