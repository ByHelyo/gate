#include "http/request/ipv6address.h"
#include "http/request/h16.h"
#include "http/request/misc.h"
#include "misc/vector/iter.h"

enum ParseResult ipv6address_parse(struct IterVec *http) {
  while (1) {
    struct IterResult ret = iterVec_peek(http);

    if (!ret.status) {
      break;
    }

    if (is_hexdig(ret.ch)) {
      if (!h16_parse(http)) {
        return ParseErr;
      }
    }
  }

  return ParseErr;
}
