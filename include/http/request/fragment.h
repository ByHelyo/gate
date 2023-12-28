#ifndef GATE_FRAGMENT_H
#define GATE_FRAGMENT_H

#include "http/request/request.h"

enum ParseResult fragment_parse(struct IterVec *http);

#endif // GATE_FRAGMENT_H
