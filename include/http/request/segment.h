#ifndef GATE_SEGMENT_H
#define GATE_SEGMENT_H

#include "http/request/parse_result.h"

struct IterVec;

enum ParseResult segment_parse(struct IterVec *http);

#endif // GATE_SEGMENT_H
