#include <misc/vector/iter.h>

#include <misc/vector/vector.h>

struct IterResult iterResult_build(void) {
  struct IterResult ret;
  ret.ch = '\0';
  ret.status = IterNone;

  return ret;
}

void iterVec_init(struct IterVec *iterVec, struct Vec *vec) {
  iterVec->vec = vec;
  iterVec->idx = 0;
}

struct IterResult iterVec_peek(struct IterVec *iterVec) {
  struct IterResult ret = iterResult_build();

  if (iterVec->idx < iterVec->vec->size) {
    ret.status = IterSome;
    ret.ch = vec_get(iterVec->vec, iterVec->idx);
  }

  return ret;
}

struct IterResult iterVec_next(struct IterVec *iterVec) {
  struct IterResult ret = iterResult_build();

  if (iterVec->idx < iterVec->vec->size) {
    ret.ch = vec_get(iterVec->vec, iterVec->idx);
    ret.status = IterSome;
    ++iterVec->idx;
  }

  return ret;
}
