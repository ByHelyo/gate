#ifndef GATE_REQUEST_TARGET_H
#define GATE_REQUEST_TARGET_H

#include "http/request/parse_result.h"

struct IterVec;

enum ParseResult request_target_parse(struct IterVec *http);

#endif // GATE_REQUEST_TARGET_H
