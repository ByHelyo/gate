#include <core/core.h>
#include <stdio.h>

#define PORT "5173"

int main(void) {
  int rv;
  struct Event event;

  rv = event_build(&event, PORT);

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
