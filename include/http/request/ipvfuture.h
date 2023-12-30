#ifndef GATE_IPVFUTURE_H
#define GATE_IPVFUTURE_H

#include "http/request/parse_result.h"

struct IterVec;

enum ParseResult ipvfuture_parse(struct IterVec *http);

#endif // GATE_IPVFUTURE_H
