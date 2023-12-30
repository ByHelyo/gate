#ifndef GATE_UNRESERVED_H
#define GATE_UNRESERVED_H

#include "http/request/parse_result.h"

struct IterVec;

int is_unreserved(char ch);

enum ParseResult unreserved_parse(struct IterVec *http);

#endif // GATE_UNRESERVED_H
