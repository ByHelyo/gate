#include <socket/socket.h>

#include <errno.h>
#include <logger/log.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int close_wrap(int fd) {
  if (close(fd) == -1) {
    log_error("failed to close the file descriptor '%i': %s", fd,
              strerror(errno));

    return -1;
  }

  return 0;
}

int socket_wrap(int domain, int type, int protocol) {
  int sockfd = socket(domain, type, protocol);

  if (sockfd == -1) {
    log_error("socket failed to create an endpoint for communication: %s",
              strerror(errno));
    return -1;
  }

  return sockfd;
}

int bind_wrap(int sockfd, const struct sockaddr *addr, socklen_t addrlen) {
  if (bind(sockfd, addr, addrlen) == -1) {
    log_error("bind failed for file descriptor '%i': %s", sockfd,
              strerror(errno));
    return -1;
  }

  return 0;
}

int listen_wrap(int sockfd) {
  if (listen(sockfd, SOMAXCONN) == -1) {
    log_error("failed to listen for file descriptor '%i': %s", sockfd,
              strerror(errno));
    return -1;
  }

  return 0;
}

int accept_wrap(int listener_fd, struct sockaddr *restrict addr,
                socklen_t *restrict addrlen) {
  int sockfd = accept(listener_fd, addr, addrlen);

  if (sockfd == -1) {
    log_error("Failed to accept the socket from the listener socket '%i': %s",
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
      log_error("failed to send data to the socket '%i': %s", sockfd,
                strerror(errno));
      break;
    }

    total += (size_t)n;
    bytes_left -= (size_t)n;
  }

  return total == len;
}

ssize_t recv_wrap(int sockfd, void *buf, size_t len, int flags) {
  ssize_t ret;

  ret = recv(sockfd, buf, len, flags);

  if (ret == -1) {
    log_error("failed to receive data from the socket '%i': %s", sockfd,
              strerror(errno));
    return -1;
  }

  return ret;
}
