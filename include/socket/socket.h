#ifndef GATE_SOCKET_H
#define GATE_SOCKET_H

#include <sys/socket.h>

/**
 * \brief Wrapper of close(2) syscall.
 *
 * @param fd File descriptor to close.
 * @return Return 0 on success otherwise return -1.
 */
int close_wrap(int fd);

/**
 * \brief Wrapper of socket(2) syscall.
 *
 * @param domain Socket domain.
 * @param type Socket type.
 * @param protocol Socket protocol.
 * @return Return a file descriptor for the new socket.
 */
int socket_wrap(int domain, int type, int protocol);

/**
 * \brief Wrapper of bind(2) syscall.
 *
 * @param sockfd Socket to bind.
 * @param addr Address assigned to the socket.
 * @param addrlen Specifies the size, in bytes, of the address structure pointed
 * to by addr.
 * @return Return 0 on sucess otherwise return -1.
 */
int bind_wrap(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

/**
 * \brief Wrapper of listen(2) syscall.
 *
 * @param sockfd Socket file descriptor to listen.
 * @param backlog Maximum length to which the queue of pending connections.
 * @return Return 0 on sucess otherwise return -1.
 */
int listen_wrap(int sockfd, int backlog);

/**
 *
 * \brief Wrapper of accept(2) syscall.
 *
 * @param sockfd The listener socket.
 * @param addr addr is filled with the address of new connection.
 * @param addrlen Size of addr in bytes.
 * @return Return a file descriptor for the accepted socket. On error, return
 * -1.
 */
int accept_wrap(int sockfd, struct sockaddr *restrict addr,
                socklen_t *restrict addrlen);

/**
 * \brief Wrapper of send(2) syscall.
 *
 * @param sockfd file descriptor to send bytes.
 * @param buf Bytes to send.
 * @param len Number of bytes to send.
 * @param flags Flags for send(2).
 * @return Return 0 on success otherwise return -1.
 */
int send_wrap(int sockfd, const void *buf, size_t len, int flags);

#endif // GATE_SOCKET_H
