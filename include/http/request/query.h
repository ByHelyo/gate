#ifndef GATE_QUERY_H
#define GATE_QUERY_H

#include "http/request/parse_result.h"

struct IterVec;

enum ParseResult query_parse(struct IterVec *http);

#endif // GATE_QUERY_H
