#include "http/request/userinfo.h"

#include "http/request/pct_encoded.h"
#include "http/request/sub_delims.h"
#include "http/request/unreserved.h"
#include "misc/vector/iter.h"

int is_userinfo(char ch) {
  return is_unreserved(ch) || is_pct_encoded(ch) || is_sub_delims(ch) ||
         ch == ':';
}

enum ParseResult userinfo_parse(struct IterVec *http) {
  while (1) {
    struct IterResult ret = iterVec_peek(http);

    if (!ret.status) {
      return ParseOk;
    }

    if (is_unreserved(ret.ch)) {
      if (!unreserved_parse(http)) {
        return ParseErr;
      }
    } else if (is_pct_encoded(ret.ch)) {
      if (!pct_encoded_parse(http)) {
        return ParseErr;
      }
    } else if (is_sub_delims(ret.ch)) {
      if (!sub_delims_parse(http)) {
        return ParseErr;
      }
    } else if (ret.ch == ':') {
      iterVec_next(http);
    } else {
      return ParseOk;
    }
  }
}
