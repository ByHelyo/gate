#ifndef GATE_AUTHORITY_H
#define GATE_AUTHORITY_H

#include "http/request/request.h"

enum ParseResult authority_parse(struct IterVec *http);

#endif // GATE_AUTHORITY_H
