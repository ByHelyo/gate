#include "http/request/absolute_uri.h"
#include "http/request/scheme.h"

enum ParseResult absolute_uri_parse(struct IterVec *http) {
  if (scheme_parse(http) == ParseErr) {
    return ParseErr;
  }

  return ParseErr;
}
