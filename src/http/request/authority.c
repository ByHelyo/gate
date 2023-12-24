#include "http/request/authority.h"

#include "http/request/userinfo.h"
#include "misc/vector/iter.h"

enum ParseResult authority_parse(struct IterVec *http) {
  struct IterResult ret = iterVec_peek(http);

  if (is_userinfo(ret.ch)) {
    if (!userinfo_parse(http)) {
      return ParseErr;
    }

    ret = iterVec_peek(http);

    if (ret.status && ret.ch == '@') {
      iterVec_next(http);
    }
  }

  return ParseErr;
}
