#include <core/core.h>

#include <stdio.h>

int core_run(struct Event *event) {
  int running = 1;
  unsigned int current_ev;

  while (running) {
    if (event_wait(event) == -1) {
      return -1;
    }

    for (current_ev = 0; current_ev < event->event_ready.size; ++current_ev) {
      if (event->event_ready.events[current_ev].data.fd == event->listener) {
        printf("Listener socket\n");
      }
    }
  }

  return 0;
}
