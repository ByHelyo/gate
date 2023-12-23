#include "http/request/pchar.h"

#include "http/request/pct_encoded.h"
#include "http/request/sub_delims.h"
#include "http/request/unreserved.h"

int is_pchar(char ch) {
  return is_unreserved(ch) || is_pct_encoded(ch) || is_sub_delims(ch);
}
