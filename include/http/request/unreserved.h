#ifndef GATE_UNRESERVED_H
#define GATE_UNRESERVED_H

#include "http/request/request.h"

struct IterVec;

int is_unreserved(char ch);

enum ParseResult unreserved_parse(struct IterVec *http);

#endif // GATE_UNRESERVED_H
