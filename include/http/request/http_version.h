#ifndef GATE_HTTP_VERSION_H
#define GATE_HTTP_VERSION_H

#include "http/request/parse_result.h"

struct IterVec;

enum ParseResult http_version_parse(struct IterVec *http);

#endif // GATE_HTTP_VERSION_H
