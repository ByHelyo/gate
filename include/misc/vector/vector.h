#ifndef GATE_VECTOR_H
#define GATE_VECTOR_H

#include <stddef.h>

struct Vec {
  size_t size;
  size_t capacity;
  char *data;
};

/**
 * \brief Builds a vector.
 *
 * @param vec The vector.
 */
void vec_build(struct Vec *vec);

/**
 * \brief Appends a character to the back of a collection.
 *
 * @param vec The vector.
 * @param character The character to add.
 * @return Return 0 on success otherwise return -1.
 */
int vec_push(struct Vec *vec, char character);

/**
 * \brief Clears the vector.
 *
 * @param vec The vector
 */
void vec_destroy(struct Vec *vec);

#endif // GATE_VECTOR_H
