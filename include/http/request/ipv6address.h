#ifndef GATE_IPV6ADDRESS_H
#define GATE_IPV6ADDRESS_H

#include "http/request/parse_result.h"

struct IterVec;

enum ParseResult ipv6address_parse(struct IterVec *http);

#endif // GATE_IPV6ADDRESS_H
