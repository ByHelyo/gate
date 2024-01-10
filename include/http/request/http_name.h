#ifndef GATE_HTTP_NAME_H
#define GATE_HTTP_NAME_H

#include "http/request/parse_result.h"

struct IterVec;

enum ParseResult http_name_parse(struct IterVec *http);

#endif // GATE_HTTP_NAME_H
