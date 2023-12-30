#ifndef GATE_ORIGIN_FORM_H
#define GATE_ORIGIN_FORM_H

#include "http/request/parse_result.h"

struct IterVec;

enum ParseResult origin_form_parse(struct IterVec *http);

#endif // GATE_ORIGIN_FORM_H
