#ifndef GATE_H16_H
#define GATE_H16_H

#include "http/request/parse_result.h"

struct IterVec;

enum ParseResult h16_parse(struct IterVec *http);

#endif // GATE_H16_H
