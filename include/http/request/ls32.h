#ifndef GATE_LS32_H
#define GATE_LS32_H

#include "http/request/parse_result.h"

struct IterVec;

enum ParseResult ls32_parse(struct IterVec *http);

#endif // GATE_LS32_H
