#ifndef GATE_EVENT_H
#define GATE_EVENT_H

/**
 * Create an epoll instance
 *
 * @return Return a file descriptor referring to the new epoll instance. On
 * error, print the error and return -1.
 */
int event_build(void);

#endif // GATE_EVENT_H
