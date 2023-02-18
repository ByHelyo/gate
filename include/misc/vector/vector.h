#ifndef GATE_VECTOR_H
#define GATE_VECTOR_H

#include <stddef.h>

struct Vec {
  size_t size;
  size_t capacity;
  void **data;
};

/**
 * \brief Build a vector.
 *
 * @param vec The vector.
 * @return On success, return 0 otherwise return -1.
 */
int vec_build(struct Vec *vec);

/**
 * \brief Add an element to the vector.
 *
 * @param vec The vector.
 * @param elt The element to add.
 * @return Return 0 on success otherwise return -1.
 */
int vec_push(struct Vec *vec, void *elt);

/**
 * \brief Clear the vector.
 *
 * @param vec The vector
 * @param free_func Free function used to free elements.
 */
void vec_clear(struct Vec *vec, void (*free_func)(void *));

#endif // GATE_VECTOR_H
