#ifndef GATE_EVENT_H
#define GATE_EVENT_H

struct Event {
  int epfd;
  int listener;
};

/**
 * \brief Build an event instance passed by argument.
 *
 * Create a new epoll instance and a listener socket.
 * Add the listener socket in the epoll instance as EPOLLIN.
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

#endif // GATE_EVENT_H
