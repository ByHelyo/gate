#include <event/event_data.h>

#include <errno.h>
#include <logger/log.h>
#include <socket/socket.h>
#include <stdlib.h>
#include <string.h>

struct EventData *eventdata_build(int fd) {
  struct EventData *event_data;
  if (fd < 0) {
    log_error(
        "failed to build an EventData: a file descriptor cannot be negative");
    return NULL; /* File descriptor is non negative */
  }

  event_data = calloc(1, sizeof(struct EventData));

  if (event_data == NULL) {
    log_error("allocation of EventData for file descriptor '%i' failed: %s", fd,
              strerror(errno));
    return NULL;
  }

  event_data->fd = fd;
  vec_build(&event_data->data);

  return event_data;
}

int eventdata_destroy(struct EventData *event_data) {
  int rv = 0;

  vec_free(&event_data->data);

  rv = close_wrap(event_data->fd);

  free(event_data);

  return rv;
}
