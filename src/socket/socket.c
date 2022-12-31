#include <socket/socket.h>

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int close_wrap(int fd) {
  if (close(fd) == -1) {
    fprintf(stderr, "Failed to close the file descriptor %i: %s\n", fd,
            strerror(errno));
    return -1;
  }

  return 0;
}

int socket_wrap(int domain, int type, int protocol) {
  int sockfd = socket(domain, type, protocol);

  if (sockfd == -1) {
    perror("Socket failed to create an endpoint for communication");
    return -1;
  }

  return sockfd;
}

int bind_wrap(int sockfd, const struct sockaddr *addr, socklen_t addrlen) {
  if (bind(sockfd, addr, addrlen) == -1) {
    fprintf(stderr, "Bind failed for file descriptor %i: %s\n", sockfd,
            strerror(errno));
    return -1;
  }

  return 0;
}

int listen_wrap(int sockfd, int backlog) {
  if (listen(sockfd, backlog) == -1) {
    fprintf(stderr, "Failed to listen for file descriptor %i: %s\n", sockfd,
            strerror(errno));
    return -1;
  }

  return 0;
}

int accept_wrap(int listener_fd, struct sockaddr *restrict addr,
                socklen_t *restrict addrlen) {
  int sockfd = accept(listener_fd, addr, addrlen);

  if (sockfd == -1) {
    fprintf(stderr,
            "Failed to accept the socket from the listener socket %i: %s\n",
            sockfd, strerror(errno));
    return -1;
  }

  return sockfd;
}

int send_wrap(int sockfd, const void *buf, size_t len, int flags) {
  const char *ptr_buf = buf; /* Convert void* to char* for arithmetics */
  size_t total = 0;
  size_t bytes_left = len;
  ssize_t n;

  while (total < len) {
    n = send(sockfd, ptr_buf + total, bytes_left, flags);

    if (n == -1) {
      break;
    }

    total += (size_t)n;
    bytes_left -= (size_t)n;
  }

  return total == len;
}
