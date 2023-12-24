#include "http/request/pchar.h"

#include "http/request/pct_encoded.h"
#include "http/request/sub_delims.h"
#include "http/request/unreserved.h"
#include "misc/vector/iter.h"

int is_pchar(char ch) {
  return is_unreserved(ch) || is_pct_encoded(ch) || is_sub_delims(ch);
}

enum ParseResult pchar_parse(struct IterVec *http) {
  struct IterResult ret = iterVec_peek(http);

  if (!ret.status) {
    return ParseErr;
  }

  if (is_unreserved(ret.ch)) {
    return unreserved_parse(http);
  }

  if (is_pct_encoded(ret.ch)) {
    return pct_encoded_parse(http);
  }

  if (is_sub_delims(ret.ch)) {
    return sub_delims_parse(http);
  }

  return ParseErr;
}
