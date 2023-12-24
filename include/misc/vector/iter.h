#ifndef GATE_ITER_H
#define GATE_ITER_H

#include <stddef.h>

/**
 * @enum IterStatus
 * \brief Represents the status of an iterator.
 *
 * Enumerates the possible states an iterator can have: IterSome (indicating a
 * valid value) and IterNone (indicating no value).
 */
enum IterStatus {
  IterNone, // Iterator has no value
  IterSome, // Iterator has a valid value
};

/**
 * @struct IterResult
 * \brief Represents the result of an iteration.
 *
 * Contains the status of the iterator (IterSome or IterNone) and the associated
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
 * \brief Initializes an iterator for the given Vec.
 *
 * Initializes the IterVec structure to create an iterator for the provided Vec.
 *
 * @param iterVec Pointer to the IterVec structure to be initialized.
 * @param vec Pointer to the Vec structure to be iterated.
 */
void iterVec_init(struct IterVec *iterVec, struct Vec *vec);

/**
 * \brief Peeks at the next element in the Vec using the iterator.
 *
 * Retrieves the next element from the Vec being iterated by the provided
 * iterator without advancing the iterator position.
 *
 * @param iterVec Pointer to the iterator over the Vec.
 * @return Returns an IterResult structure containing the status and the next
 * element. The 'status' field in the returned structure indicates if the
 * iterator has a valid value (IterStatus IterSome) or not (IterStatus
 * IterNone). The 'ch' field contains the character associated with the iterator
 * status.
 */
struct IterResult iterVec_peek(struct IterVec *iterVec);

/**
 * \brief Retrieve the next element in the Vec using the iterator.
 *
 * Retrieves the next element from the Vec being iterated by the provided
 * iterator without advancing the iterator position.
 *
 * @param iterVec Pointer to the iterator over the Vec.
 * @return Returns an IterResult structure containing the status and the next
 * element. The 'status' field in the returned structure indicates whether the
 * iterator has a valid value (IterStatus IterSome) or not (IterStatus
 * IterNone). If the iterator has a valid value, 'ch' contains the character
 * associated with the iterator status.
 */
struct IterResult iterVec_next(struct IterVec *iterVec);

#endif // GATE_ITER_H
