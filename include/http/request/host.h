#ifndef GATE_HOST_H
#define GATE_HOST_H

#include "http/request//request.h"

struct IterVec;

enum ParseResult host_parse(struct IterVec *http);

#endif // GATE_HOST_H
