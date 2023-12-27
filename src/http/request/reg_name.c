#include "http/request/reg_name.h"

#include "http/request/pct_encoded.h"
#include "http/request/sub_delims.h"
#include "http/request/unreserved.h"
#include "misc/vector/iter.h"

enum ParseResult reg_name_parse(struct IterVec *http) {

  while (1) {
    struct IterResult ret = iterVec_peek(http);

    if (!ret.status) {
      return ParseOk;
    }

    if (is_unreserved(ret.ch)) {
      iterVec_next(http);
    } else if (is_pct_encoded(ret.ch)) {
      if (!pct_encoded_parse(http)) {
        return ParseErr;
      }
    } else if (is_sub_delims(ret.ch)) {
      iterVec_next(http);
    } else {
      return ParseOk;
    }
  }
}
