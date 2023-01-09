#include <event/event_data.h>

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct EventData *build_event_data(int fd) {
  struct EventData *event_data;
  if (fd < 0) {
    fprintf(
        stderr,
        "Failed to build an EventData: A file descriptor cannot be negative\n");
    return NULL; /* File descriptor is non negative */
  }

  event_data = calloc(1, sizeof(struct EventData));

  if (event_data == NULL) {
    fprintf(stderr,
            "Allocation of EventData for file descriptor %i failed : %s\n", fd,
            strerror(errno));
    return NULL;
  }

  event_data->fd = fd;

  return event_data;
}
