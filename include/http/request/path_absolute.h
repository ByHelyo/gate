#ifndef GATE_PATH_ABSOLUTE_H
#define GATE_PATH_ABSOLUTE_H

#include "http/request/parse_result.h"

struct IterVec;

enum ParseResult path_absolute_parse(struct IterVec *http);

#endif // GATE_PATH_ABSOLUTE_H
