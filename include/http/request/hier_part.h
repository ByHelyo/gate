#ifndef GATE_HIER_PART_H
#define GATE_HIER_PART_H

#include "http/request/parse_result.h"

struct IterVec;

enum ParseResult hier_part_parse(struct IterVec *http);

#endif // GATE_HIER_PART_H
