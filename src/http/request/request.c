#include "http/request/request.h"

#include "http/request/method.h"
#include "http/request/misc.h"
#include "misc/vector/iter.h"

enum ParseResult request_parse(struct IterVec *http, struct TrieNode *methods) {
  if (method_parse(http, methods) == ParseErr) {
    return ParseErr;
  }

  if (sp_parse(http) == ParseErr) {
    return ParseErr;
  }

  return ParseOk;
}
