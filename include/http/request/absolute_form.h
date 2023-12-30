#ifndef GATE_ABSOLUTE_FORM_H
#define GATE_ABSOLUTE_FORM_H

#include "http/request/parse_result.h"

struct IterVec;

enum ParseResult absolute_form_parse(struct IterVec *http);

#endif // GATE_ABSOLUTE_FORM_H
