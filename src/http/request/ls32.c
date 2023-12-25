#include "http/request/ls32.h"

#include "http/request/h16.h"
#include "http/request/ipv4address.h"
#include "misc/vector/iter.h"

enum ParseResult ls32_parse(struct IterVec *http) {
  struct IterResult first = iterVec_peek(http);
  struct IterResult second = iterVec_nth(http, 1);
  struct IterResult third = iterVec_nth(http, 2);
  struct IterResult fourth = iterVec_nth(http, 3);
  struct IterResult fifth = iterVec_nth(http, 4);

  if (first.ch == ':' || second.ch == ':' || third.ch == ':' ||
      fourth.ch == ':' || fifth.ch == ':') {
    if (!h16_parse(http)) {
      return ParseErr;
    }
    struct IterResult ret = iterVec_next(http);

    if (!ret.status || ret.ch != ':') {
      return ParseErr;
    }

    return h16_parse(http);
  }

  return ipv4address_parse(http);
}
