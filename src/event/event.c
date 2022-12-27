#include <errno.h>
#include <event/event.h>
#include <stdio.h>
#include <string.h>
#include <sys/epoll.h>

int event_build(void) {
  int epfd;

  if ((epfd = epoll_create1(0)) == -1) {
    fprintf(stderr, "[event_build] Failed to create epoll instance: %s\n",
            strerror(errno));
    return -1;
  } else {
    return epfd;
  }
}
