#include "http/request/authority.h"

#include "http/request/host.h"
#include "http/request/port.h"
#include "http/request/userinfo.h"
#include "misc/vector/iter.h"

enum ParseResult authority_parse(struct IterVec *http) {
  struct IterVec save;
  iterVec_copy(http, &save);
  struct IterResult ret = iterVec_peek(http);

  if (ret.status == IterNone) {
    return ParseOk;
  }

  if (is_userinfo(ret.ch)) {
    if (!userinfo_parse(http)) {
      return ParseErr;
    }

    ret = iterVec_peek(http);

    if (ret.status && ret.ch == '@') {
      iterVec_next(http);
    } else {
      iterVec_copy(&save, http);
    }
  }

  if (!host_parse(http)) {
    return ParseErr;
  }

  ret = iterVec_peek(http);

  if (!ret.status || ret.ch != ':') {
    return ParseOk;
  }

  iterVec_next(http);

  return port_parse(http);
}
