#ifndef GATE_EVENT_H
#define GATE_EVENT_H

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
  unsigned int size;                     /**< Number of events ready. */
  struct epoll_event events[MAX_EVENTS]; /**< The events ready. */
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
 * \brief Build an event instance passed by argument. Event behaves
 * level-triggered (LT).
 *
 * Create a new epoll instance and a listener socket.
 * Add the listener socket in the epoll instance as EPOLLIN.
 *
 * If an error occurred. Return -1 and everything is freed properly.
 *
 * EPOLLIN The associated file is available for read(2) operations.
 *
 * @param event The event instance to build. Careful every fields will be
 * overwritten.
 * @param port Port to listen
 * @param listen_queue_backlog Maximum length to which the queue of pending
 * connections.
 * @return Return 0 on sucess otherwise return -1.
 */
int event_build(struct Event *event, const char *port,
                int listen_queue_backlog);

/**
 * \brief Wait for I/O events.
 *
 * Use epoll_wait(2) to wait events.
 * Fetch ready events and store them in event's member event_ready.
 *
 * @param event The event instance.
 * @return Return the number of events ready. On failure, return -1.
 */
int event_wait(struct Event *event);

/**
 * \brief Accept a new connection and add it in epoll.
 *
 * Accept the new connection in listener socket.
 * Add the new connection in epoll.
 *
 * @param event The event instance.
 * @return On success, return 0 otherwise return -1.
 */
int event_accept(struct Event *event);

/**
 * \brief Close the event instance.
 *
 * Close the listener file descriptor then the epoll file descriptor.
 *
 * @param event The event instance.
 * @return Return 0 on success, otherwise return -1.
 */
int event_close(struct Event *event);

#endif // GATE_EVENT_H
