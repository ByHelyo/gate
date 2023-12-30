#ifndef GATE_SCHEME_H
#define GATE_SCHEME_H

#include "http/request/parse_result.h"

struct IterVec;

enum ParseResult scheme_parse(struct IterVec *http);

#endif // GATE_SCHEME_H
