#ifndef GATE_PCT_ENCODED_H
#define GATE_PCT_ENCODED_H

#include "http/request/parse_result.h"

struct IterVec;

int is_pct_encoded(char ch);

enum ParseResult pct_encoded_parse(struct IterVec *http);

#endif // GATE_PCT_ENCODED_H
