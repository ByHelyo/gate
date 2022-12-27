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
    fprintf(stderr,
            "Socket failed to create an endpoint for communication: %s\n",
            strerror(errno));
    return -1;
  }

  return sockfd;
}

int bind_wrap(int sockfd, const struct sockaddr *addr, socklen_t addrlen) {
  if (bind(sockfd, addr, addrlen) == -1) {
    fprintf(stderr, "Bind failed: %s\n", strerror(errno));
    return -1;
  }

  return 0;
}

int listen_wrap(int sockfd, int backlog) {
  if (listen(sockfd, backlog) == -1) {
    fprintf(stderr, "Failed to listen: %s\n", strerror(errno));
    return -1;
  }

  return 0;
}
