#include "http/request/authority.h"

#include "http/request/host.h"
#include "http/request/userinfo.h"
#include "misc/vector/iter.h"

enum ParseResult authority_parse(struct IterVec *http) {
  struct IterResult ret = iterVec_peek(http);

  if (ret.status == IterNone) {
    // TODO !
  }

  if (is_userinfo(ret.ch)) {
    if (!userinfo_parse(http)) {
      return ParseErr;
    }

    ret = iterVec_peek(http);

    if (ret.status && ret.ch == '@') {
      iterVec_next(http);
    }
  }

  if (!host_parse(http)) {
    return ParseErr;
  }

  return ParseErr;
}
