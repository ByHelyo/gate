#include "http/request/http_name.h"

#include "http/request/misc.h"
#include <string.h>

enum ParseResult http_name_parse(struct IterVec *http) {
  char http_name[] = "http";
  size_t n = strlen(http_name);

  for (size_t i = 0; i < n; ++i) {
    if (!char_parse(http, http_name[i])) {
      return ParseErr;
    }
  }

  return ParseOk;
}