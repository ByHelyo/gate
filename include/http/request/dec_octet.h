#ifndef GATE_DEC_OCTET_H
#define GATE_DEC_OCTET_H

#include "http/request/parse_result.h"

struct IterVec;

enum ParseResult dec_octet_parse(struct IterVec *http);

#endif // GATE_DEC_OCTET_H
