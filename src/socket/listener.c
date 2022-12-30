#include <socket/listener.h>

#include <netdb.h>
#include <socket/socket.h>
#include <stdio.h>
#include <string.h>

static struct addrinfo build_hints_addrinfo(void);

int build_listener_socket(const char *port, int listen_queue_backlog) {
  int listener = -1; /* listener socket */
  int rv;            /* return value */
  struct addrinfo *p, *result;
  struct addrinfo hints = build_hints_addrinfo();

  rv = getaddrinfo(NULL, port, &hints, &result);

  if (rv != 0) {
    fprintf(stderr, "getaddrinfo failed for listener socket: %s\n",
            gai_strerror(rv));
    return -1;
  }

  for (p = result; p != NULL; p = p->ai_next) {
    listener = socket_wrap(p->ai_family, p->ai_socktype, p->ai_protocol);

    if (listener == -1) {
      continue;
    }

    if (bind_wrap(listener, p->ai_addr, p->ai_addrlen) == 0) {
      break; /* Success */
    }

    close_wrap(listener);
  }

  freeaddrinfo(result);

  if (p == NULL) {
    return -1;
  }

  rv = listen_wrap(listener, listen_queue_backlog);

  if (rv == -1) {
    close_wrap(listener);
    return -1;
  }

  printf("Listener socket created sucessfully (file descriptor %i)\n",
         listener);

  return listener;
}

static struct addrinfo build_hints_addrinfo(void) {
  struct addrinfo hints;
  memset(&hints, 0, sizeof(struct addrinfo));

  hints.ai_family = AF_UNSPEC;     /* Allow IPv4 or IPv6 */
  hints.ai_socktype = SOCK_STREAM; /* Stream socket */
  hints.ai_flags = AI_PASSIVE;     /* local host address */

  return hints;
}
