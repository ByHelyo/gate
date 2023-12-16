#include <event/event.h>

#include <errno.h>
#include <event/event_data.h>
#include <logger/log.h>
#include <socket/listener.h>
#include <socket/socket.h>
#include <string.h>

int event_build(struct Event *event, const char *port) {
  struct epoll_event listener_ev;

  if ((event->epfd = epoll_create1(0)) == -1) {
    log_error("failed to create epoll instance: %s", strerror(errno));
    return -1;
  }

  log_info("epoll file descriptor '%i' created successfully", event->epfd);

  event->listener = build_listener_socket(port);

  if (event->listener == -1) {
    close_wrap(
        event->epfd); /* Listener socket failed. Free epoll file descriptor */
    return -1;
  }

  if ((listener_ev.data.ptr = eventdata_build(event->listener)) == NULL) {
    return -1;
  }

  listener_ev.events = EPOLLIN;

  if (epoll_ctl(event->epfd, EPOLL_CTL_ADD, event->listener, &listener_ev) ==
      -1) {
    log_error("failed to add listener socket in epoll: %s", strerror(errno));

    // Failed to add listener in epoll. Free listener and epoll file
    // descriptors.
    close_wrap(event->listener);
    close_wrap(event->epfd);

    return -1;
  }

  log_info("event created successfully");

  return 0;
}

int event_wait(struct Event *event) {
  int nfds = epoll_wait(event->epfd, event->event_ready.events, MAX_EVENTS, -1);

  if (nfds == -1) {
    log_error("waiting for events failed: %s", strerror(errno));

    return -1;
  }

  log_info("%i events ready", nfds);

  event->event_ready.size = nfds;

  return 0;
}

int event_accept(struct Event *event) {
  struct epoll_event ev;
  int conn_sock = accept_wrap(event->listener, NULL, NULL);

  if (conn_sock == -1) {
    return -1; /* Accept failed */
  }

  ev.events = EPOLLIN;
  if ((ev.data.ptr = eventdata_build(conn_sock)) == NULL) {
    return -1;
  }

  if (epoll_ctl(event->epfd, EPOLL_CTL_ADD, conn_sock, &ev) == -1) {
    log_error(
        "failed to add a new connection (file descriptor %i) to epoll: %s",
        conn_sock, strerror(errno));
    close_wrap(conn_sock); /* Free the connection socket. */
    return -1;
  }

  log_info("new connection with file descriptor '%i'", conn_sock);

  return 0;
}

int event_free(struct Event *event) {
  int rv;

  int ret = 0;

  rv = close_wrap(event->listener);

  if (rv == -1) {
    log_error("failed to close listener file descriptor: %s", strerror(errno));
    ret = -1;
  } else {
    log_info("listener file descriptor closed successfully");
  }

  rv = close_wrap(event->epfd);

  if (rv == -1) {
    log_error("failed to close epoll file descriptor: %s", strerror(errno));
    ret = -1;
  } else {
    log_info("epoll file descriptor closed successfully");
  }

  log_info("event closed sucessfully");

  return ret;
}

int event_read(struct EventData *event_data) {
  ssize_t rv;
  char buffer[1024] = {0};

  rv = recv_wrap(event_data->fd, buffer, 1024, 0);

  if (rv == 0) {
    return 0;
  } else if (rv == -1) {
    return -1;
  }

  vec_push_str(&event_data->data, buffer, (size_t)rv);

  return 1;
}

int event_close(struct EventData *event_data) {
  return eventdata_destroy(event_data);
}
