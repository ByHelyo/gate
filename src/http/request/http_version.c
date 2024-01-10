#include "http/request/http_version.h"

#include "http/request/http_name.h"
#include "http/request/misc.h"

enum ParseResult http_version_parse(struct IterVec *http) {
  if (!http_name_parse(http)) {
    return ParseErr;
  }

  if (!char_parse(http, '/')) {
    return ParseErr;
  }

  return ParseOk;
}
