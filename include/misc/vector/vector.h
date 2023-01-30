#ifndef GATE_VECTOR_H
#define GATE_VECTOR_H

#include <stddef.h>

struct Vec {
  size_t size;
  size_t capacity;
  size_t elt_size;
  void *data;
};

/**
 * \brief Build a vector.
 *
 * @param vec The vector
 * @param size size of an element in bytes.
 * @return On success, return 1 otherwise return 0.
 */
int vec_build(struct Vec *vec, size_t size);

int vec_push(struct Vec *vec, void *elt);

#endif // GATE_VECTOR_H
