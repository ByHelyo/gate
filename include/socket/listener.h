#ifndef GATE_LISTENER_H
#define GATE_LISTENER_H

/**
 * Builds the listener socket
 *
 * @param port Listener socket port.
 * @return Returns the listener socket. On error, prints the error and returns
 * -1.
 */
int build_listener_socket(const char *port);

#endif // GATE_LISTENER_H
