#ifndef GATE_PCHAR_H
#define GATE_PCHAR_H

#include "http/request/request.h"

struct IterVec;

int is_pchar(char ch);

enum ParseResult pchar_parse(struct IterVec *http);

#endif // GATE_PCHAR_H
