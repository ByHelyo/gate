#include "http/request/unreserved.h"
#include <http/request/pchar.h>

int is_pchar(char ch) { return is_unreserved(ch); }
