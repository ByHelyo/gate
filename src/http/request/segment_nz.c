#include "http/request/segment_nz.h"

#include "http/request/pchar.h"
#include "misc/vector/iter.h"

enum ParseResult segment_nz_parse(struct IterVec *http) {
  unsigned int count = 0;
  while (1) {
    struct IterResult ret = iterVec_peek(http);

    if (!ret.status || !is_pchar(ret.ch)) {
      break;
    }

    if (!pchar_parse(http)) {
      return ParseErr;
    }

    ++count;
  }

  return count > 0 ? ParseOk : ParseErr;
}
