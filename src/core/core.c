#include <core/core.h>

#include <event/event_data.h>

int core_run(struct Event *event) {
  int running = 1;
  int current_ev;
  int rv;
  struct EventData *event_data;

  while (running) {
    if (event_wait(event) == -1) {
      running = 0;
    }

    for (current_ev = 0; current_ev < event->event_ready.size; ++current_ev) {
      event_data = event->event_ready.events[current_ev].data.ptr;

      if (event_data->fd == event->listener) {
        event_accept(event);
      } else {
        rv = event_read(event_data);

        switch (rv) {
        case 0:
          event_close(event_data);
          break;
        case -1:
          break;
        default:
          break;
        }
      }
    }
  }

  return 0;
}
