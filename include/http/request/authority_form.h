#ifndef GATE_AUTHORITY_FORM_H
#define GATE_AUTHORITY_FORM_H

#include "http/request/parse_result.h"

struct IterVec;

enum ParseResult authority_form_parse(struct IterVec *http);

#endif // GATE_AUTHORITY_FORM_H
