#include <http/request/segment.h>

#include "http/request/pchar.h"
#include "misc/vector/iter.h"

void segment_parse(struct IterVec *http) {
  while (1) {
    struct IterResult ret = iterVec_peek(http);

    if (ret.status == IterNone) {
      return;
    }

    if (!is_pchar(ret.ch)) {
      return;
    }

    iterVec_next(http);
  }
}
