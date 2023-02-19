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
 * \brief Appends a buffer of characters of size len at the end of the
 * collection.
 *
 * @param vec The vector.
 * @param buf The buffer of characters.
 * @param len Number of characters to add in the vector.
 * @return Returns 0 on success otherwise returns -1.
 */
int vec_push_str(struct Vec *vec, char *buf, size_t len);

/**
 * \brief Clears the vector.
 *
 * @param vec The vector
 */
void vec_destroy(struct Vec *vec);

#endif // GATE_VECTOR_H
