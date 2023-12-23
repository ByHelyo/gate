#ifndef GATE_MISC_H
#define GATE_MISC_H

#include "http/request/request.h"

enum ParseResult sp_parse(struct IterVec *http);

int is_alpha(char ch);

int is_digit(char ch);

#endif // GATE_MISC_H
