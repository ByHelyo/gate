#ifndef GATE_ABSOLUTE_PATH_H
#define GATE_ABSOLUTE_PATH_H

#include "http/request/parse_result.h"

struct IterVec;

enum ParseResult absolute_path_parse(struct IterVec *http);

#endif // GATE_ABSOLUTE_PATH_H
