#ifndef GATE_REQUEST_TARGET_H
#define GATE_REQUEST_TARGET_H

#include "http/request/request.h"

enum ParseResult request_target_parse(struct IterVec *http);

#endif // GATE_REQUEST_TARGET_H
