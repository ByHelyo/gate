#include <http/request/request_target.h>

#include <http/request/origin_form.h>
#include <misc/vector/iter.h>

enum ParseResult request_target_parse(struct IterVec *http) {

  struct IterResult ret = iterVec_peek(http);

  if (ret.status == IterNone) {
    return ParseErr;
  }

  if (ret.ch == '/') {
    if (origin_form_parse(http) == ParseErr) {
      return ParseErr;
    }
  }

  return ParseOk;
}
