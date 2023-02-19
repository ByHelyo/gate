#ifndef GATE_LISTENER_H
#define GATE_LISTENER_H

/*!
  \def BACKLOG_LISTENER
  Maximum number of connections allowed in the socket's listener queue.
*/
#define BACKLOG_LISTENER 20

/**
 * Builds the listener socket
 *
 * @param port Listener socket port.
 * @return Returns the listener socket. On error, prints the error and returns
 * -1.
 */
int build_listener_socket(const char *port);

#endif // GATE_LISTENER_H
