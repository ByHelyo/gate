#include <socket/socket.h>

#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

static void populate_hints_addrinfo(struct addrinfo **hints);

int build_listener_socket(const char *port, int listen_queue_backlog) {
  int listener = -1; /* listener scoket */
  int rv;            /* return value */

  struct addrinfo hints, *p, *result;

  struct addrinfo *phints = &hints;

  populate_hints_addrinfo(&phints);

  if ((rv = getaddrinfo(NULL, port, &hints, &result)) != 0) {
    fprintf(stderr, "[build_listener_socket] getaddrinfo failed: %s\n",
            gai_strerror(rv));
    return -1;
  }

  for (p = result; p != NULL; p = p->ai_next) {
    listener = socket(p->ai_family, p->ai_socktype, p->ai_protocol);

    if (listener == -1) {
      fprintf(stderr, "[build_listener_socket] socket() failed: %s\n", strerror(errno));
      continue;
    }

    if (bind(listener, p->ai_addr, p->ai_addrlen) == 0) {
      break; /* Success */
    }

    fprintf(stderr, "[build_listener_socket] Failed to bind: %s\n", strerror(errno));
    close(listener);
  }

  freeaddrinfo(result);

  if (p == NULL) {
    return -1;
  }

  if ((rv = listen(listener, listen_queue_backlog)) == -1) {
    fprintf(stderr, "[build_listener_socket] Failed to listen: %s\n", strerror(rv));
  }

  return listener;
}

static void populate_hints_addrinfo(struct addrinfo **hints) {
  memset(*hints, 0, sizeof(struct addrinfo));

  (*hints)->ai_family = AF_UNSPEC;     /* Allow IPv4 or IPv6 */
  (*hints)->ai_socktype = SOCK_STREAM; /* Stream socket */
  (*hints)->ai_flags = AI_PASSIVE;     /* local host address */
}
