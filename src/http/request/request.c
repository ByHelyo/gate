#include "http/request/request.h"

#include "http/request/method.h"
#include "misc/vector/iter.h"

enum ParseResult request_parse(struct IterVec *http, struct TrieNode *methods) {
  method_parse(http, methods);
  return ParseOk;
}
