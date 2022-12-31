#include <event/event.h>

#include <errno.h>
#include <event/event_data.h>
#include <socket/listener.h>
#include <socket/socket.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int event_build(struct Event *event, const char *port,
                int listen_queue_backlog) {
  struct epoll_event listener_ev;

  if ((event->epfd = epoll_create1(0)) == -1) {
    perror("Failed to create epoll instance");
    return -1;
  }

  printf("Epoll file descriptor created successfully (file descriptor %i)\n",
         event->epfd);

  event->listener = build_listener_socket(port, listen_queue_backlog);

  if (event->listener == -1) {
    close_wrap(
        event->epfd); /* Listener socket failed. Free epoll file descriptor */
    return -1;
  }

  listener_ev.data.ptr = build_event_data(event->listener);
  listener_ev.events = EPOLLIN;

  if (epoll_ctl(event->epfd, EPOLL_CTL_ADD, event->listener, &listener_ev) ==
      -1) {
    perror("Failed to add listener socket in epoll");

    // Failed to add listener in epoll. Free listener and epoll file
    // descriptors.
    close_wrap(event->listener);
    close_wrap(event->epfd);

    return -1;
  }

  printf("Event created successfully\n");

  return 0;
}

int event_wait(struct Event *event) {
  int nfds = epoll_wait(event->epfd, event->event_ready.events, MAX_EVENTS, -1);

  if (nfds == -1) {
    perror("Waiting for events failed");

    return -1;
  }

  printf("%i events ready\n", nfds);

  event->event_ready.size = (unsigned int)nfds;

  return 0;
}

int event_accept(struct Event *event) {
  struct epoll_event ev;
  int conn_sock = accept_wrap(event->listener, NULL, NULL);

  if (conn_sock == -1) {
    return -1; /* Accept failed */
  }

  ev.events = EPOLLIN;
  ev.data.ptr = build_event_data(conn_sock);

  if (epoll_ctl(event->epfd, EPOLL_CTL_ADD, conn_sock, &ev) == -1) {
    fprintf(
        stderr,
        "Failed to add a new connection (file descriptor %i) in epoll: %s\n",
        conn_sock, strerror(errno));
    close_wrap(conn_sock); /* Free the connection socket. */
    return -1;
  }

  return 0;
}

int event_close(struct Event *event) {
  int rv;

  int ret = 0;

  rv = close(event->listener);

  if (rv == -1) {
    perror("failed to close listener file descriptor");
    ret = -1;
  } else {
    printf("Listener file descriptor closed successfully\n");
  }

  rv = close(event->epfd);

  if (rv == -1) {
    perror("Failed to close epoll file descriptor");
    ret = -1;
  } else {
    printf("Epoll file descriptor closed successfully\n");
  }

  printf("Event close successfully\n");

  return ret;
}
