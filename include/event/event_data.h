#ifndef GATE_EVENT_DATA_H
#define GATE_EVENT_DATA_H

#include <misc/vector/vector.h>

struct TrieNode;

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
 * constructing an HTTP request using specified methods.
 *
 * This function examines the event data to determine if it contains the
 * required data for building an HTTP request based on the specified methods
 * stored in a TrieNode.
 *
 * @param event_data The event data containing data for the HTTP request.
 * @param methods Pointer to the TrieNode storing allowed HTTP methods.
 * @return Returns 1 if the HTTP request can be constructed using the given
 * event data and allowed methods, otherwise returns 0.
 */
int eventdata_parse(struct EventData *event_data, struct TrieNode *methods);

#endif // GATE_EVENT_DATA_H
