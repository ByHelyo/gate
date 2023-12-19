#ifndef GATE_EVENT_H
#define GATE_EVENT_H

#include <sys/epoll.h>

struct EventData;

/*!
  \def MAX_EVENTS
  Maximum number of events ready per epoll_wait(2) call.
*/
#define MAX_EVENTS 20

/**
 * EventReady stores results from epoll_wait(2) call.
 */
struct EventReady {
  int size;                              /**< Number of events ready. */
  struct epoll_event events[MAX_EVENTS]; /**< The ready events. */
};

/**
 * Event manages an epoll instance and a listener socket.
 */
struct Event {
  int epfd;                      /**< Epoll file descriptor */
  int listener;                  /**< Listener file descriptor */
  struct EventReady event_ready; /**< Store results of epoll_wait(2) */
};

/**
 * \brief Initializes an event instance passed by argument. Event behaves
 * level-triggered (LT).
 *
 * Creates a new epoll instance and a listener socket.
 * Adds the listener socket in the epoll instance as EPOLLIN.
 *
 * If an error occurred, returns -1 and everything is freed properly.
 *
 * EPOLLIN The associated file is available for read(2) operations.
 *
 * @param event The event instance to build. Careful every fields will be
 * overwritten.
 * @param port Port to listen
 * @return Return 0 on sucess otherwise return -1.
 */
int event_init(struct Event *event, const char *port);

/**
 * \brief Waits for I/O events.
 *
 * Use epoll_wait(2) to wait events.
 * Fetches ready events and stores them in event's member event_ready.
 *
 * @param event The event instance.
 * @return Returns the number of events ready. On failure, returns -1.
 */
int event_wait(struct Event *event);

/**
 * \brief Accepts a new connection and adds it in epoll.
 *
 * Accepts the new connection in listener socket.
 * Adds the new connection in epoll.
 *
 * @param event The event instance.
 * @return On success, returns 0 otherwise returns -1.
 */
int event_accept(struct Event *event);

/**
 * \brief Frees the event instance fields.
 *
 * Closes the listener file descriptor then the epoll file descriptor.
 *
 * @param event The event instance.
 * @return Returns 0 on success, otherwise returns -1.
 */
int event_free(struct Event *event);

/**
 * \brief Reads data from a connection.
 *
 * @param event_data Event data connection.
 * @return Returns 1 on success, 0 if the connection is closed or -1 on error.
 */
int event_read(struct EventData *event_data);

/**
 * \brief Close a connection by closing its file descriptor.
 *
 * @param event_data Event data associated to the connection.
 * @return Returns 0 on success otherwise returns -1.
 */
int event_close(struct EventData *event_data);

/**
 * @brief Gets the number of events ready.
 *
 * This function retrieves the number of events that are currently ready in the
 * provided Event structure.
 *
 * @param event Pointer to the Event structure.
 * @return Returns the number of events ready.
 */
int event_size(struct Event *event);

/**
 * @brief Gets event data from a specified index.
 *
 * This function retrieves event data from the provided Event structure at the
 * specified index.
 *
 * @param event Pointer to the Event structure.
 * @param index Index of the event data to retrieve.
 * @return Returns a pointer to the event data at the specified index.
 */
void *event_get(struct Event *event, int index);

/**
 * @brief Checks if the EventData is the listener associated with the Event.
 *
 * This function checks whether the provided EventData structure corresponds to
 * the listener associated with the given Event structure.
 *
 * @param event Pointer to the Event structure.
 * @param event_data Pointer to the EventData structure to be checked.
 * @return Returns 1 if the EventData is the listener associated with the Event,
 * otherwise 0.
 */
int is_listener(struct Event *event, struct EventData *event_data);

#endif // GATE_EVENT_H
