#include "http/request/sub_delims.h"
#include "misc/vector/iter.h"

int is_sub_delims(char ch) {
  return ch == '!' || ch == '$' || ch == '&' || ch == '\'' || ch == '(' ||
         ch == ')' || ch == '*' || ch == '+' || ch == ',' || ch == ';' ||
         ch == '=';
}

enum ParseResult sub_delims_parse(struct IterVec *http) {
  struct IterResult ret = iterVec_next(http);

  if (ret.status != IterNone && !is_sub_delims(ret.ch)) {
    return ParseErr;
  }

  return ParseOk;
}
