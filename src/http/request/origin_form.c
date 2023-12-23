#include "http/request/absolute_path.h"

#include "http/request/origin_form.h"

enum ParseResult origin_form_parse(struct IterVec *http) {
  if (absolute_path_parse(http)) {
    return ParseErr;
  }

  return ParseOk;
}
