#ifndef GATE_ITER_H
#define GATE_ITER_H

#include <stddef.h>

/**
 * @struct IterVec
 * \brief Iterator structure for Vec.
 *
 * This structure represents an iterator used for iterating through elements
 * within the Vec (vector) data structure.
 */
struct IterVec {
  struct Vec *vec;
  size_t idx;
};

#endif // GATE_ITER_H
