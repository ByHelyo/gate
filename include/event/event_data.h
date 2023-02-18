#ifndef GATE_EVENT_DATA_H
#define GATE_EVENT_DATA_H

#include <misc/vector/vector.h>

/**
 * Structure used to store data for an event.
 */
struct EventData {
  int fd;
  struct Vec data;
};

/**
 * \brief Build an EventData instance for a file descriptor.
 *
 * @param fd File descriptor bound to EventData.
 * @return Return EventData pointer. On error, return NULL.
 */
struct EventData *build_event_data(int fd);

#endif // GATE_EVENT_DATA_H
