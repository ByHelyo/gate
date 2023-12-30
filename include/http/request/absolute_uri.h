#ifndef GATE_ABSOLUTE_URI_H
#define GATE_ABSOLUTE_URI_H

#include "http/request/parse_result.h"

struct IterVec;

enum ParseResult absolute_uri_parse(struct IterVec *http);

#endif // GATE_ABSOLUTE_URI_H
