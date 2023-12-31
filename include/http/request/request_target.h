#ifndef GATE_REQUEST_TARGET_H
#define GATE_REQUEST_TARGET_H

#include "http/request/parse_result.h"

struct Request;
struct IterVec;

enum ParseResult request_target_parse(struct IterVec *http,
                                      struct Request *request);

#endif // GATE_REQUEST_TARGET_H
