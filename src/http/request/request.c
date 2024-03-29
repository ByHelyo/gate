#include "http/request/request.h"

#include "http/request/http_version.h"
#include "http/request/method.h"
#include "http/request/misc.h"
#include "http/request/request_target.h"
#include "misc/vector/iter.h"

enum ParseResult request_parse(struct IterVec *http, struct Request *request,
                               struct TrieNode *methods) {
  if (!method_parse(http, request, methods)) {
    return ParseErr;
  }

  if (!sp_parse(http)) {
    return ParseErr;
  }

  if (!request_target_parse(http, request)) {
    return ParseErr;
  }

  if (!sp_parse(http)) {
    return ParseErr;
  }

  if (!http_version_parse(http)) {
    return ParseErr;
  }

  return ParseOk;
}
