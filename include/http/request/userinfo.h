#ifndef GATE_USERINFO_H
#define GATE_USERINFO_H

#include "http/request/parse_result.h"

struct IterVec;

int is_userinfo(char ch);

enum ParseResult userinfo_parse(struct IterVec *http);

#endif // GATE_USERINFO_H
