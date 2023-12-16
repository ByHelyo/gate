#ifndef GATE_METHOD_H
#define GATE_METHOD_H

#include <http/request/request.h>

enum Method {
  GET,
  HEAD,
  POST,
  PUT,
  DELETE,
  CONNECT,
  OPTIONS,
  TRACE,
  PATCH,
};

enum ParseResult method_parse(struct IterVec *http);

#endif // GATE_METHOD_H
