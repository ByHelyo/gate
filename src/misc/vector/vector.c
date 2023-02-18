#include "misc/vector/vector.h"

#include <stdio.h>
#include <stdlib.h>

static int vec_extend_capacity(struct Vec *vec);

int vec_build(struct Vec *vec) {
  vec->size = 0;
  vec->capacity = 2;
  vec->data = calloc(vec->capacity, sizeof(void *));

  if (vec->data == NULL) {
    fprintf(stderr, "Failed to allocate %zu bytes to build a vector",
            sizeof(void *) * vec->capacity);
    return -1;
  }

  return 0;
}

void vec_clear(struct Vec *vec, void (*free_func)(void *)) {
  size_t idx = 0;
  if (free_func != NULL) {
    for (; idx < vec->size; ++idx) {
      free_func(vec->data[idx]);
    }
  }

  vec->capacity = 0;
  vec->size = 0;
  free(vec->data);
}

int vec_push(struct Vec *vec, void *elt) {
  if (vec->size == vec->capacity) {
    if (vec_extend_capacity(vec) == -1) {
      return -1;
    }
  }

  vec->data[vec->size] = elt;
  ++vec->size;

  return 0;
}

static int vec_extend_capacity(struct Vec *vec) {
  void *new_ptr;
  vec->capacity = vec->capacity * 2;
  size_t new_size = vec->capacity * sizeof(void *);

  new_ptr = realloc(vec->data, new_size);

  if (new_ptr == NULL) {
    fprintf(stderr, "Failed to allocate %zu bytes to expand a vector",
            new_size);
    return -1;
  }

  vec->data = new_ptr;
  return 0;
}
