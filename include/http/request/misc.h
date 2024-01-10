#ifndef GATE_MISC_H
#define GATE_MISC_H

#include "http/request/parse_result.h"

struct IterVec;

enum ParseResult sp_parse(struct IterVec *http);

enum ParseResult char_parse(struct IterVec *http, char ch);

int is_alpha(char ch);

int is_digit(char ch);

int is_hexdig(char ch);

#endif // GATE_MISC_H
