#ifndef GATE_USERINFO_H
#define GATE_USERINFO_H

#include "http/request/request.h"

enum ParseResult userinfo_parse(struct IterVec *http);

#endif // GATE_USERINFO_H
