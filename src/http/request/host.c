#include "http/request/host.h"
#include "http/request/ip_literal.h"
#include "http/request/ipv4address.h"
#include "http/request/reg_name.h"
#include "misc/vector/iter.h"

enum ParseResult host_parse(struct IterVec *http) {
  struct IterVec save;
  iterVec_copy(http, &save);
  struct IterResult ret = iterVec_peek(http);

  if (!ret.status) {
    return ParseOk;
  }

  if (ip_literal_parse(http)) {
    return ParseOk;
  }

  iterVec_copy(&save, http);

  if (ipv4address_parse(http)) {
    return ParseOk;
  }

  iterVec_copy(&save, http);

  return reg_name_parse(http);
}
