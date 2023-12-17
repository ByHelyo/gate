#include <core/core.h>
#include <logger/log.h>
#include <stdio.h>

#define PORT "5173"

int main(void) {
  int rv;
  struct Event event;

  rv = event_init(&event, PORT);
  log_info("listening on http://localhost:%s", PORT);

  if (rv == -1) {
    goto end; /* Failure, File descriptors are already closed. */
  }

  rv = core_run(&event);

  event_free(&event);

end:
  fclose(stdin);
  fclose(stderr);
  fclose(stdout);

  return rv;
}
