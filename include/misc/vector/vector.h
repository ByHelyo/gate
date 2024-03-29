#ifndef GATE_VECTOR_H
#define GATE_VECTOR_H

#include <stddef.h>

struct Vec {
  size_t size;
  size_t capacity;
  char *data;
};

/**
 * \brief Initializes a vector.
 *
 * @param vec The vector.
 */
void vec_init(struct Vec *vec);

/**
 * \brief Appends a character to the back of a collection.
 *
 * @param vec The vector.
 * @param character The character to add.
 * @return Return 0 on success otherwise return -1.
 */
int vec_push(struct Vec *vec, char character);

/**
 * @brief Appends a buffer of characters of size len at the end of the
 * collection.
 *
 * This function appends a buffer of characters to the end of the given vector.
 *
 * @param vec Pointer to the vector where characters will be appended.
 * @param buf Pointer to the buffer of characters to be appended.
 * @param len Number of characters to add to the vector.
 * @return Returns 0 on success, otherwise returns -1.
 */
int vec_push_str(struct Vec *vec, const char *buf, size_t len);

/**
 * @brief Gets a character at the specified index from a Vec.
 *
 * Retrieves a character from the provided Vec structure at the specified index.
 *
 * @param vec Pointer to the Vec structure.
 * @param index The index of the character to retrieve.
 * @return Returns the character at the specified index in the Vec.
 */
char vec_get(struct Vec *vec, size_t index);

/**
 * \brief Frees the vector data.
 *
 * @param vec The vector.
 */
void vec_free(struct Vec *vec);

/**
 * \brief Print the vector.
 *
 * @param vec Vector to print.
 */
void vec_print(struct Vec *vec);

#endif // GATE_VECTOR_H
