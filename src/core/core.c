#include <core/core.h>

int core_init(struct Event *event, const char *port) {
  return event_build(event, port, 10);
}

int core_close(struct Event *event) { return event_close(event); }
