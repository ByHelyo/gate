#ifndef GATE_SOCKET_H
#define GATE_SOCKET_H

#include <sys/socket.h>

/**
 * \brief Wrapper of close(2) syscall.
 *
 * @param fd File descriptor to close.
 * @return Returns 0 on success otherwise returns -1.
 */
int close_wrap(int fd);

/**
 * \brief Wrapper of socket(2) syscall.
 *
 * @param domain Socket domain.
 * @param type Socket type.
 * @param protocol Socket protocol.
 * @return Returns a file descriptor for the new socket.
 */
int socket_wrap(int domain, int type, int protocol);

/**
 * \brief Wrapper of bind(2) syscall.
 *
 * @param sockfd Socket to bind.
 * @param addr Address assigned to the socket.
 * @param addrlen Specifies the size, in bytes, of the address structure pointed
 * to by addr.
 * @return Returns 0 on sucess otherwise returns -1.
 */
int bind_wrap(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

/**
 * \brief Wrapper of listen(2) syscall.
 *
 * @param sockfd Socket file descriptor to listen.
 * @param backlog Maximum length to which the queue of pending connections.
 * @return Returns 0 on sucess otherwise returns -1.
 */
int listen_wrap(int sockfd, int backlog);

/**
 *
 * \brief Wrapper of accept(2) syscall.
 *
 * @param listener_fd The listener socket.
 * @param addr addr is filled with the address of new connection.
 * @param addrlen Size of addr in bytes.
 * @return Returns a file descriptor for the accepted socket. On error, returns
 * -1.
 */
int accept_wrap(int listener_fd, struct sockaddr *restrict addr,
                socklen_t *restrict addrlen);

/**
 * \brief Wrapper of send(2) syscall.
 *
 * @param sockfd file descriptor to send bytes.
 * @param buf Bytes to send.
 * @param len Number of bytes to send.
 * @param flags Flags for send(2).
 * @return Returns 0 on success otherwise returns -1.
 */
int send_wrap(int sockfd, const void *buf, size_t len, int flags);

/**
 * \brief Wrapper of recv(2) syscall.
 *
 * @param sockfd file descriptor to read.
 * @param buf buffer to save data read from sockfd.
 * @param len Size of the buffer.
 * @param flags Flags for recv(2).
 * @return Returns 0 if file descriptor is closed. Returns the number of bytes
 * read or -1 on error.
 */
ssize_t recv_wrap(int sockfd, void *buf, size_t len, int flags);

#endif // GATE_SOCKET_H
