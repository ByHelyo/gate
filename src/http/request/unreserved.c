#include "http/request/unreserved.h"

#include "http/request/misc.h"

int is_unreserved(char ch) {
  return is_alpha(ch) || is_digit(ch) || ch == '-' || ch == '.' || ch == '_' ||
         ch == '~';
}
