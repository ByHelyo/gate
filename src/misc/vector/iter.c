#include <misc/vector/iter.h>

#include <misc/vector/vector.h>

struct IterResult iter_result_build(void) {
  struct IterResult ret;
  ret.ch = '\0';
  ret.status = IterErr;

  return ret;
}

void iter_vec_build(struct IterVec *iter_vec, struct Vec *vec) {
  iter_vec->vec = vec;
  iter_vec->idx = 0;
}

struct IterResult iter_vec_peek(struct IterVec *iter_vec) {
  struct IterResult ret = iter_result_build();

  if (iter_vec->idx < iter_vec->vec->size) {
    ret.status = IterOk;
    ret.ch = iter_vec->vec->data[iter_vec->idx];
  }

  return ret;
}

struct IterResult iter_vec_next(struct IterVec *iter_vec) {
  struct IterResult ret = iter_result_build();

  if (iter_vec->idx < iter_vec->vec->size) {
    ++iter_vec->idx;
    ret.status = IterOk;
  }

  return ret;
}
