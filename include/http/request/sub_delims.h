#ifndef GATE_SUB_DELIMS_H
#define GATE_SUB_DELIMS_H

#include "http/request/parse_result.h"

struct IterVec;

int is_sub_delims(char ch);

enum ParseResult sub_delims_parse(struct IterVec *http);

#endif // GATE_SUB_DELIMS_H
