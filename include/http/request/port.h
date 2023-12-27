#ifndef GATE_PORT_H
#define GATE_PORT_H

#include "http/request/request.h"

enum ParseResult port_parse(struct IterVec *http);

#endif // GATE_PORT_H
