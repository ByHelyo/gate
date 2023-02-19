#ifndef GATE_EVENT_DATA_H
#define GATE_EVENT_DATA_H

#include <misc/vector/vector.h>

/**
 * Structure used to store data for an event.
 */
struct EventData {
  int fd;          /**< File descriptor bound to this event data. */
  struct Vec data; /**< Data received from the file descriptor. */
};

/**
 * \brief Builds an EventData instance for a file descriptor.
 *
 * @param fd File descriptor bound to EventData.
 * @return Returns EventData pointer. On error, returns NULL.
 */
struct EventData *build_event_data(int fd);

#endif // GATE_EVENT_DATA_H
