#include <misc/vector/vector.h>

#include <logger/log.h>
#include <misc/math/math.h>
#include <stdlib.h>
#include <string.h>

static int vec_grow(struct Vec *vec, size_t *capacity);
static int vec_allocate(struct Vec *vec, size_t size);

void vec_init(struct Vec *vec) {
  vec->size = 0;
  vec->capacity = 0;
  vec->data = NULL;
}

void vec_free(struct Vec *vec) {
  vec->capacity = 0;
  vec->size = 0;
  free(vec->data);
  vec->data = NULL;
}

int vec_push(struct Vec *vec, char elt) {
  if (vec->size == vec->capacity) {
    if (vec_grow(vec, NULL) == -1) {
      return -1;
    }
  }

  vec->data[vec->size] = elt;
  ++vec->size;

  return 0;
}

int vec_push_str(struct Vec *vec, char *buf, size_t len) {
  if (vec_grow(vec, &len) == -1) {
    return -1;
  }

  memcpy(vec->data + vec->size, buf, len);
  vec->size += len;

  return 0;
}

char vec_get(struct Vec *vec, size_t index) { return vec->data[index]; }

void vec_print(struct Vec *vec) {
  log_info("vector: %.*s", vec->size, vec->data);
}

static int vec_grow(struct Vec *vec, size_t *capacity) {
  size_t new_capacity;

  if (capacity == NULL) {
    if (vec->capacity == 0) {
      new_capacity = 8;
    } else {
      new_capacity = vec->capacity << 1;
    }
  } else {
    new_capacity = next_pow2(*capacity);
  }

  return vec_allocate(vec, new_capacity);
}

static int vec_allocate(struct Vec *vec, size_t size) {
  char *new_ptr;

  vec->capacity = size;

  new_ptr = realloc(vec->data, size);

  if (new_ptr == NULL) {
    log_error("failed to allocate %zu bytes for grow a vector", size);
    return -1;
  }

  vec->data = new_ptr;
  return 0;
}
