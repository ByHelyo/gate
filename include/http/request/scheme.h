#ifndef GATE_SCHEME_H
#define GATE_SCHEME_H

#include "http/request/request.h"

enum ParseResult scheme_parse(struct IterVec *http);

#endif // GATE_SCHEME_H
