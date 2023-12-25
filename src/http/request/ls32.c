#include "http/request/ls32.h"
#include "http/request/h16.h"
#include "http/request/ipv4address.h"
#include "misc/vector/iter.h"

enum ParseResult ls32_parse(struct IterVec *http) {
  if (h16_parse(http)) {
    struct IterResult ret = iterVec_peek(http);

    if (!ret.status || ret.ch != ':') {
      return ParseErr;
    }

    return h16_parse(http);
  }

  return ipv4address_parse(http);
}
