#include "core/core.h"

#include "event/event_data.h"
#include "http/request/method.h"
#include "misc/trie/trie.h"

int core_run(struct Event *event) {
  int running = 1;
  int current_ev;
  int rv;
  struct EventData *event_data;
  struct TrieNode methods;

  methods_trieInit(&methods); // TODO : error

  while (running) {
    if (event_wait(event) == -1) {
      running = 0;
    }

    for (current_ev = 0; current_ev < event_size(event); ++current_ev) {
      event_data = event_get(event, current_ev);

      if (is_listener(event, event_data)) {
        event_accept(event);
      } else {
        rv = event_read(event_data);
        eventdata_parse(event_data, &methods);

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
