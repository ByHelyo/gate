#include "misc/vector/vector.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int vec_extend_capacity(struct Vec *vec);

void vec_build(struct Vec *vec) {
  vec->size = 0;
  vec->capacity = 0;
  vec->data = NULL;
}

void vec_free(struct Vec *vec) {
  vec->capacity = 0;
  vec->size = 0;
  free(vec->data);
}

int vec_push(struct Vec *vec, char elt) {
  if (vec->size == vec->capacity) {
    if (vec_extend_capacity(vec) == -1) {
      return -1;
    }
  }

  vec->data[vec->size] = elt;
  ++vec->size;
  return 0;
}

int vec_push_str(struct Vec *vec, char *buf, size_t len) {
  while (vec->size + len > vec->capacity) {
    if (vec_extend_capacity(vec) == -1) {
      return -1;
    }
  }

  memcpy(vec->data + vec->size, buf, len);
  vec->size += len;

  return 0;
}

static int vec_extend_capacity(struct Vec *vec) {
  char *new_ptr;

  if (vec->capacity == 0) {
    vec->capacity = 8;
  } else {
    vec->capacity = vec->capacity << 1;
  }

  size_t new_size = vec->capacity;

  new_ptr = realloc(vec->data, new_size);

  if (new_ptr == NULL) {
    fprintf(stderr, "Failed to allocate %zu bytes to expand a vector",
            new_size);
    return -1;
  }

  vec->data = new_ptr;
  return 0;
}
