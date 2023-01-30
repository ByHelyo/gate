#include "misc/vector/vector.h"

#include <stdio.h>
#include <stdlib.h>

int vec_build(struct Vec *vec, size_t size) {
  vec->size = 0;
  vec->capacity = 2;
  vec->elt_size = size;
  vec->data = calloc(vec->capacity, sizeof(size));

  if (vec->data == NULL) {
    perror("Failed to build a vector");
    return 0;
  }

  return 1;
}

int vec_push(struct Vec *vec, void *elt) { return 0; }

static int vec_extend_capacity(struct Vec *vec) {
  void *new_ptr;
  vec->capacity = vec->capacity * 2;

  new_ptr = realloc(vec->data, vec->capacity * vec->elt_size);

  if (new_ptr == NULL) {
    return 0;
  }

  vec->data = new_ptr;
  return 1;
}
