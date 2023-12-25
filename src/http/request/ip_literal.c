#include "http/request/ip_literal.h"

#include "http/request/ipv6address.h"
#include "misc/vector/iter.h"

enum ParseResult ip_literal_parse(struct IterVec *http) {
  struct IterResult ret = iterVec_next(http);

  if (!ret.status || ret.ch != '[') {
    return ParseErr;
  }

  ret = iterVec_peek(http);

  if (!ret.status) {
    return ParseErr;
  }

  return ret.ch == 'v' ? ipv6address_parse(http) : ipv6address_parse(http);
}
