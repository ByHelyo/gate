#ifndef GATE_SOCKET_H
#define GATE_SOCKET_H

/**
 * Build the listener socket
 *
 * @param port Listener socket port.
 * @param listen_queue_backlog Number of connections in the socket's listen
 * queue.
 * @return Return the listener socket. On error, print the error and return -1.
 */
int build_listener_socket(const char *port, int listen_queue_backlog);

#endif // GATE_SOCKET_H
