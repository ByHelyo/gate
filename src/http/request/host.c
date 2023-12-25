#include "http/request/host.h"
#include "http/request/ip_literal.h"
#include "misc/vector/iter.h"

enum ParseResult host_parse(struct IterVec *http) {
  struct IterResult ret = iterVec_peek(http);

  if (ret.status == IterNone) {
    // TODO !
  }

  if (ret.ch == '[') {
    if (!ip_literal_parse(http)) {
      return ParseErr;
    }
  }

  return ParseErr;
}
