#ifndef GATE_USERINFO_H
#define GATE_USERINFO_H

#include "http/request/request.h"

int is_userinfo(char ch);

enum ParseResult userinfo_parse(struct IterVec *http);

#endif // GATE_USERINFO_H
