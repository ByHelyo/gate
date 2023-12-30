#ifndef GATE_IPV4ADDRESS_H
#define GATE_IPV4ADDRESS_H

#include "http/request/parse_result.h"

struct IterVec;

enum ParseResult ipv4address_parse(struct IterVec *http);

#endif // GATE_IPV4ADDRESS_H
