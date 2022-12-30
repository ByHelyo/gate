#include <event/event.h>

#include <errno.h>
#include <socket/listener.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int event_build(struct Event *event, const char *port,
                int listen_queue_backlog) {
  struct epoll_event listener_ev;

  if ((event->epfd = epoll_create1(0)) == -1) {
    fprintf(stderr, "Failed to create epoll instance: %s\n", strerror(errno));
    return -1;
  }

  event->listener = build_listener_socket(port, listen_queue_backlog);

  listener_ev.data.fd = event->listener;
  listener_ev.events = EPOLLIN;

  if (epoll_ctl(event->epfd, EPOLL_CTL_ADD, event->listener, &listener_ev) ==
      -1) {
    fprintf(stderr, "Failed to add listener socket in epoll: %s\n",
            strerror(errno));
    return -1;
  }

  printf("Event created successfully (epoll file descriptor %i)\n",
         event->epfd);

  return 0;
}

int event_wait(struct Event *event) {
  int nfds = epoll_wait(event->epfd, event->event_ready.events, MAX_EVENTS, -1);

  if (nfds == -1) {
    fprintf(stderr, "Waiting for events failed: %s\n", strerror(errno));

    return -1;
  }

  printf("%i events ready\n", nfds);

  event->event_ready.size = (unsigned int)nfds;

  return 0;
}

int event_close(struct Event *event) {

  int ret = 0;

  if (close(event->listener) == -1) {
    fprintf(stderr, "Failed to close listener file descriptor: %s\n",
            strerror(errno));
    ret = -1;
  }

  if (close(event->epfd) == -1) {
    fprintf(stderr, "Failed to close epoll file descriptor: %s\n",
            strerror(errno));
    ret = -1;
  }

  printf("Event close successfully\n");

  return ret;
}
