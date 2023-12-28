#include "http/request/request_target.h"

#include "http/request/absolute_form.h"
#include "http/request/asterik_form.h"
#include "http/request/authority_form.h"
#include "http/request/misc.h"
#include "http/request/origin_form.h"
#include "misc/vector/iter.h"

enum ParseResult request_target_parse(struct IterVec *http) {
  struct IterVec save;
  iterVec_copy(http, &save);
  struct IterResult ret = iterVec_peek(http);

  if (!ret.status) {
    return ParseErr;
  }

  if (ret.ch == '/') {
    if (origin_form_parse(http)) {
      return ParseOk;
    }
  } else if (is_alpha(ret.ch)) {
    if (absolute_form_parse(http)) {
      return ParseOk;
    }
  } else if (ret.ch == '*') {
    if (asterik_form_parse(http)) {
      return ParseOk;
    }
  }

  iterVec_copy(&save, http);
  return authority_form_parse(http);
}
