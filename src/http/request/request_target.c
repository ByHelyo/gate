#include "http/request/request_target.h"

#include "http/request/absolute_form.h"
#include "http/request/asterik_form.h"
#include "http/request/authority_form.h"
#include "http/request/origin_form.h"
#include "http/request/request.h"
#include "misc/vector/iter.h"

enum ParseResult request_target_parse(struct IterVec *http,
                                      struct Request *request) {
  struct IterResult ret = iterVec_peek(http);

  if (!ret.status) {
    return ParseErr;
  }

  if (request->method == CONNECT) {
    return authority_form_parse(http);
  } else if (request->method == OPTIONS) {
    return asterik_form_parse(http);
  } else if (ret.ch == '/') {
    return origin_form_parse(http);
  } else {
    return absolute_form_parse(http);
  }
}
