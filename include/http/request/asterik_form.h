#ifndef GATE_ASTERIK_FORM_H
#define GATE_ASTERIK_FORM_H

#include "http/request/parse_result.h"

struct IterVec;

enum ParseResult asterik_form_parse(struct IterVec *http);

#endif // GATE_ASTERIK_FORM_H
