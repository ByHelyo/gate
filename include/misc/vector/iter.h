#ifndef GATE_ITER_H
#define GATE_ITER_H

#include <stddef.h>

/**
 * @enum IterStatus
 * \brief Represents the status of an iterator.
 *
 * Enumerates the possible states an iterator can have: Some (indicating a valid
 * value) and None (indicating no value).
 */
enum IterStatus {
  Some, // Iterator has a valid value
  None  // Iterator has no value
};

/**
 * @struct IterResult
 * \brief Represents the result of an iteration.
 *
 * Contains the status of the iterator (Some or None) and the associated
 * character 'ch'.
 */
struct IterResult {
  enum IterStatus status; // Status of the iterator
  char ch;                // Character associated with the iterator status
};

/**
 * @struct IterVec
 * \brief Iterator structure for Vec.
 *
 * This structure represents an iterator used for iterating through elements
 * within the Vec (vector) data structure.
 */
struct IterVec {
  struct Vec *vec; // Pointer to the Vec structure
  size_t idx;      // Current index within the Vec
};

/**
 * \brief Build an iterator for the given Vec.
 *
 * Initializes the IterVec structure to create an iterator for the provided Vec.
 *
 * @param iter_vec Pointer to the IterVec structure to be initialized.
 * @param vec Pointer to the Vec structure to be iterated.
 */
void iter_vec_build(struct IterVec *iter_vec, struct Vec *vec);

/**
 * \brief Peeks at the next element in the Vec using the iterator.
 *
 * Retrieves the next element from the Vec being iterated by the provided
 * iterator without advancing the iterator position.
 *
 * @param iter_vec Pointer to the iterator over the Vec.
 * @return Returns an IterResult structure containing the status and the next
 * element. The 'status' field in the returned structure indicates if the
 * iterator has a valid value (IterStatus Some) or not (IterStatus None). The
 * 'ch' field contains the character associated with the iterator status.
 */
struct IterResult iter_vec_peek(struct IterVec *iter_vec);

#endif // GATE_ITER_H
