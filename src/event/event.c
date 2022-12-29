#include <event/event.h>

#include <errno.h>
#include <socket/listener.h>
#include <stdio.h>
#include <string.h>
#include <sys/epoll.h>

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

  return 0;
}
