#ifndef GATE_REG_NAME_H
#define GATE_REG_NAME_H

#include "http/request/parse_result.h"

struct IterVec;

enum ParseResult reg_name_parse(struct IterVec *http);

#endif // GATE_REG_NAME_H
