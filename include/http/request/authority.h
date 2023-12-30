#ifndef GATE_AUTHORITY_H
#define GATE_AUTHORITY_H

#include "http/request/parse_result.h"

struct IterVec;

enum ParseResult authority_parse(struct IterVec *http);

#endif // GATE_AUTHORITY_H
