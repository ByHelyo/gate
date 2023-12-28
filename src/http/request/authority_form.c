#include "http/request/authority_form.h"

#include "http/request/host.h"
#include "http/request/port.h"
#include "misc/vector/iter.h"

enum ParseResult authority_form_parse(struct IterVec *http) {
  if (!host_parse(http)) {
    return ParseErr;
  }

  struct IterResult ret = iterVec_next(http);

  if (!ret.status || ret.ch != ':') {
    return ParseErr;
  }

  return port_parse(http);
}
