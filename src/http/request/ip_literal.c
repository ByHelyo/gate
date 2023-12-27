#include "http/request/ip_literal.h"

#include "http/request/ipv6address.h"
#include "http/request/ipvfuture.h"
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

  if (ret.ch != 'v') {
    ipv6address_parse(http);
  } else {
    ipvfuture_parse(http);
  }

  ret = iterVec_next(http);

  return ret.status && ret.ch == ']';
}
