#include "http/request/authority.h"
#include "http/request/pct_encoded.h"
#include "http/request/sub_delims.h"
#include "http/request/unreserved.h"
#include "http/request/userinfo.h"
#include "misc/vector/iter.h"

enum ParseResult authority_parse(struct IterVec *http) {
  struct IterResult ret = iterVec_peek(http);

  if (is_unreserved(ret.ch) || is_pct_encoded(ret.ch) ||
      is_sub_delims(ret.ch) || ret.ch == ':') {
    if (userinfo_parse(http) == ParseErr) {
      return ParseErr;
    }
  }

  return ParseErr;
}
