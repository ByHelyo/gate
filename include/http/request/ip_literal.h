#ifndef GATE_IP_LITERAL_H
#define GATE_IP_LITERAL_H

#include "http/request//request.h"

struct IterVec;

enum ParseResult ip_literal_parse(struct IterVec *http);

#endif // GATE_IP_LITERAL_H
