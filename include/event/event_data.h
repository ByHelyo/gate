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
struct EventData *eventdata_build(int fd);

/**
 * \brief Free all fields associated with event_data and event_data itself.
 *
 * @param event_data The event data to free.
 * @return Returns 0 on success otherwise returns -1.
 */
int eventdata_destroy(struct EventData *event_data);

/**
 * \brief Checks if the provided event data contains necessary information for
 * constructing an HTTP request.
 *
 * @param event_data The event data containing data for the HTTP request.
 * @return Returns 1 if the HTTP request can be constructed using the given
 * event data, otherwise returns 0.
 */
int eventdata_parse(struct EventData *event_data);

#endif // GATE_EVENT_DATA_H
