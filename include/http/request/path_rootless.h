#ifndef GATE_PATH_ROOTLESS_H
#define GATE_PATH_ROOTLESS_H

#include "http/request/parse_result.h"

struct IterVec;

enum ParseResult path_rootless_parse(struct IterVec *http);

#endif // GATE_PATH_ROOTLESS_H
