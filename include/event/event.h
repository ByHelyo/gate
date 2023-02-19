#ifndef GATE_EVENT_H
#define GATE_EVENT_H

#include <event/event_data.h>
#include <sys/epoll.h>

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
 * \brief Builds an event instance passed by argument. Event behaves
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
int event_build(struct Event *event, const char *port);

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
 * \brief Closes the event instance.
 *
 * Closes the listener file descriptor then the epoll file descriptor.
 *
 * @param event The event instance.
 * @return Returns 0 on success, otherwise returns -1.
 */
int event_close(struct Event *event);

/**
 * \brief Reads data from a connection.
 *
 * @param event_data Event data connection.
 * @return Returns 1 on success, 0 if the connection is closed or -1 on error.
 */
int event_read(struct EventData *event_data);

#endif // GATE_EVENT_H
