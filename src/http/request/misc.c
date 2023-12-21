#include <http/request/misc.h>

#include <misc/vector/iter.h>

enum ParseResult sp_parse(struct IterVec *http) {
  struct IterResult ret = iterVec_next(http);

  if (ret.status == IterNone) {
    return ParseErr;
  }

  return ret.ch == ' ' ? ParseOk : ParseErr;
}
