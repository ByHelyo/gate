#include "http/request/absolute_form.h"

#include "http/request/absolute_uri.h"

enum ParseResult absolute_form_parse(struct IterVec *http) {
  return absolute_uri_parse(http);
}
