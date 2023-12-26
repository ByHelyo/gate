#include "http/request/ipv6address.h"

#include "http/request/h16.h"
#include "http/request/ls32.h"
#include "http/request/misc.h"
#include "misc/vector/iter.h"

enum ParseResult ipv6address_parse(struct IterVec *http) {
  unsigned int count = 0;

  for (int i = 0; i < 6; ++i) {
    struct IterResult ret = iterVec_peek(http);

    if (!ret.status || !is_hexdig(ret.ch)) {
      return ParseErr;
    }

    if (!h16_parse(http)) {
      return ParseErr;
    }

    ret = iterVec_next(http);

    if (ret.status && ret.ch != ':') {
      return ParseErr;
    }

    ++count;
  }

  if (count != 6) {
    return ParseErr;
  }

  return ls32_parse(http);
}
