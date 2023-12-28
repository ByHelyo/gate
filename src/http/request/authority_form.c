#include "http/request/authority_form.h"
#include "http/request/authority.h"

enum ParseResult authority_form_parse(struct IterVec *http) {
  return authority_parse(http);
}
