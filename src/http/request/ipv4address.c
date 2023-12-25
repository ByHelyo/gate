#include "http/request/ipv4address.h"
#include "http/request/dec_octet.h"
#include "misc/vector/iter.h"

enum ParseResult ipv4address_parse(struct IterVec *http) {
  for (int i = 0; i < 3; ++i) {
    if (!dec_octet_parse(http)) {
      return ParseErr;
    }

    struct IterResult ret = iterVec_peek(http);

    if (!ret.status || ret.ch != '.') {
      return ParseErr;
    }
  }

  return dec_octet_parse(http);
}
