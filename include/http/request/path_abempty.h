#ifndef GATE_PATH_ABEMPTY_H
#define GATE_PATH_ABEMPTY_H

#include "http/request/parse_result.h"

struct IterVec;

enum ParseResult path_abempty_parse(struct IterVec *http);

#endif // GATE_PATH_ABEMPTY_H
