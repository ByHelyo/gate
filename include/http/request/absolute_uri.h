#ifndef GATE_ABSOLUTE_URI_H
#define GATE_ABSOLUTE_URI_H

#include "http/request/request.h"

enum ParseResult absolute_uri_parse(struct IterVec *http);

#endif // GATE_ABSOLUTE_URI_H
