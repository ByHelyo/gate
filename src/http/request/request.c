#include <http/request/request.h>

#include <misc/vector/iter.h>
#include <stdio.h>

enum ParseResult method_parse(struct IterVec *http) {
  printf("%c\n", iter_vec_peek(http).ch);
  return Ok;
}

enum ParseResult request_parse(struct IterVec *http) {
  method_parse(http);
  return Ok;
}
