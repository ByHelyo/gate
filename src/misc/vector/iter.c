#include <misc/vector/iter.h>

#include <misc/vector/vector.h>

void iter_vec_build(struct IterVec *iter_vec, struct Vec *vec) {
  iter_vec->vec = vec;
  iter_vec->idx = 0;
}

struct IterResult iter_vec_peek(struct IterVec *iter_vec) {
  struct IterResult ret;
  ret.ch = '\0';
  ret.status = None;

  if (iter_vec->idx < iter_vec->vec->size) {
    ret.status = Some;
    ret.ch = iter_vec->vec->data[iter_vec->idx];
  }

  return ret;
}
