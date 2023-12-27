#include "http/request/port.h"
#include "http/request/misc.h"
#include "misc/vector/iter.h"

enum ParseResult port_parse(struct IterVec *http) {
  while (1) {
    struct IterResult ret = iterVec_peek(http);

    if (!ret.status || !is_digit(ret.ch)) {
      return ParseOk;
    }

    iterVec_next(http);
  }
}
