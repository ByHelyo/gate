#include "http/request/dec_octet.h"

#include "http/request/misc.h"
#include "misc/vector/iter.h"

enum ParseResult dec_octet_parse(struct IterVec *http) {
  struct IterResult first = iterVec_peek(http);
  struct IterResult second = iterVec_nth(http, 1);
  struct IterResult third = iterVec_nth(http, 2);

  if (first.status && second.status && third.status && first.ch == '2' &&
      second.ch == '5' && third.ch >= '0' && third.ch <= '5') {
    iterVec_next(http);
    iterVec_next(http);
    iterVec_next(http);
  } else if (first.status && second.status && third.status && first.ch == '2' &&
             second.ch >= '0' && second.ch <= '4' && is_digit(third.ch)) {
    iterVec_next(http);
    iterVec_next(http);
    iterVec_next(http);
  } else if (first.status && second.status && third.status && first.ch >= '1' &&
             first.ch <= '9' && is_digit(second.ch) && is_digit(third.ch)) {
    iterVec_next(http);
    iterVec_next(http);
    iterVec_next(http);
  } else if (first.status && second.status && first.ch >= '1' &&
             first.ch <= '9' && is_digit(second.ch)) {
    iterVec_next(http);
    iterVec_next(http);
  } else if (first.status && is_digit(first.ch)) {
    iterVec_next(http);
  } else {
    return ParseErr;
  }

  return ParseOk;
}
