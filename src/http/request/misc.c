#include "http/request/misc.h"

#include "misc/vector/iter.h"

enum ParseResult sp_parse(struct IterVec *http) {
  struct IterResult ret = iterVec_next(http);

  if (!ret.status) {
    return ParseErr;
  }

  return ret.ch == ' ' ? ParseOk : ParseErr;
}

enum ParseResult char_parse(struct IterVec *http, char ch) {
  struct IterResult ret = iterVec_next(http);

  if (!ret.status) {
    return ParseErr;
  }

  return ret.ch == ch ? ParseOk : ParseErr;
}

int is_alpha(char ch) {
  return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int is_digit(char ch) { return ch >= '0' && ch <= '9'; }

int is_hexdig(char ch) {
  return is_digit(ch) || (ch >= 'A' && ch <= 'F') || (ch >= 'a' && ch <= 'f');
}
