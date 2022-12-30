#ifndef GATE_CORE_H
#define GATE_CORE_H

#include <event/event.h>

/**
 * \brief Build event instance.
 *
 * @param event The event instance.
 * @param port listener port.
 * @return Return 0 on success, -1 on error.
 */
int core_init(struct Event *event, const char *port);

/**
 * Close the event instance.
 *
 * @param event The event instance.
 * @return Return 0 on success, -1 on error.
 */
int core_close(struct Event *event);

#endif // GATE_CORE_H
