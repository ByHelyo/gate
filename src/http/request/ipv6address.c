#include "http/request/ipv6address.h"

#include "http/request/h16.h"
#include "http/request/ls32.h"
#include "http/request/misc.h"
#include "misc/vector/iter.h"

enum ParseResult first(struct IterVec *http);
enum ParseResult second(struct IterVec *http);
enum ParseResult third(struct IterVec *http);
enum ParseResult fourth(struct IterVec *http);
enum ParseResult fifth(struct IterVec *http);
enum ParseResult sixth(struct IterVec *http);
enum ParseResult seventh(struct IterVec *http);
enum ParseResult eigth(struct IterVec *http);
enum ParseResult ninth(struct IterVec *http);

enum ParseResult ipv6address_parse(struct IterVec *http) {
  struct IterVec save;
  iterVec_copy(http, &save);

  if (first(http)) {
    return ParseOk;
  }

  iterVec_copy(&save, http);

  if (second(http)) {
    return ParseOk;
  }

  iterVec_copy(&save, http);

  if (third(http)) {
    return ParseOk;
  }

  iterVec_copy(&save, http);

  if (fourth(http)) {
    return ParseOk;
  }

  iterVec_copy(&save, http);

  if (fifth(http)) {
    return ParseOk;
  }

  iterVec_copy(&save, http);

  if (sixth(http)) {
    return ParseOk;
  }

  iterVec_copy(&save, http);

  if (seventh(http)) {
    return ParseOk;
  }

  iterVec_copy(&save, http);

  if (eigth(http)) {
    return ParseOk;
  }

  iterVec_copy(&save, http);

  if (ninth(http)) {
    return ParseOk;
  }

  return ParseErr;
}

enum ParseResult first(struct IterVec *http) {
  for (int i = 0; i < 6; ++i) {
    struct IterResult ret = iterVec_peek(http);

    if (!ret.status || !is_hexdig(ret.ch)) {
      return ParseErr;
    }

    if (!h16_parse(http)) {
      return ParseErr;
    }

    ret = iterVec_next(http);

    if (ret.status && ret.ch != ':') {
      return ParseErr;
    }
  }

  return ls32_parse(http);
}

enum ParseResult second(struct IterVec *http) {
  struct IterResult first = iterVec_next(http);
  struct IterResult second = iterVec_next(http);

  if (!first.status || !second.status || first.ch != ':' || second.ch != ':') {
    return ParseErr;
  }

  for (int i = 0; i < 5; ++i) {
    struct IterResult ret = iterVec_peek(http);

    if (!ret.status || !is_hexdig(ret.ch)) {
      return ParseErr;
    }

    if (!h16_parse(http)) {
      return ParseErr;
    }

    ret = iterVec_next(http);

    if (ret.status && ret.ch != ':') {
      return ParseErr;
    }
  }

  return ls32_parse(http);
}

enum ParseResult third(struct IterVec *http) {
  struct IterResult ret = iterVec_peek(http);

  if (!ret.status) {
    return ParseErr;
  }

  if (is_hexdig(ret.ch)) {
    if (!h16_parse(http)) {
      return ParseErr;
    }
  }

  struct IterResult first = iterVec_next(http);
  struct IterResult second = iterVec_next(http);

  if (!first.status || !second.status || first.ch != ':' || second.ch != ':') {
    return ParseErr;
  }

  for (int i = 0; i < 4; ++i) {
    ret = iterVec_peek(http);

    if (!ret.status || !is_hexdig(ret.ch)) {
      return ParseErr;
    }

    if (!h16_parse(http)) {
      return ParseErr;
    }

    ret = iterVec_next(http);

    if (ret.status && ret.ch != ':') {
      return ParseErr;
    }
  }

  return ls32_parse(http);
}

enum ParseResult fourth(struct IterVec *http) {
  struct IterResult first = iterVec_peek(http);
  struct IterResult second;

  if (!first.status) {
    return ParseErr;
  }

  if (is_hexdig(first.ch)) {
    if (!h16_parse(http)) {
      return ParseErr;
    }

    for (int i = 0; i < 1; ++i) {
      first = iterVec_peek(http);
      second = iterVec_nth(http, 1);

      if (first.status && second.status && first.ch == ':' &&
          second.ch == ':') {
        break;
      }

      iterVec_next(http);

      if (!h16_parse(http)) {
        return ParseErr;
      }
    }
  }

  first = iterVec_next(http);
  second = iterVec_next(http);

  if (!first.status || !second.status || first.ch != ':' || second.ch != ':') {
    return ParseErr;
  }

  for (int i = 0; i < 3; ++i) {
    first = iterVec_peek(http);

    if (!first.status || !is_hexdig(first.ch)) {
      return ParseErr;
    }

    if (!h16_parse(http)) {
      return ParseErr;
    }

    first = iterVec_next(http);

    if (first.status && first.ch != ':') {
      return ParseErr;
    }
  }

  return ls32_parse(http);
}

enum ParseResult fifth(struct IterVec *http) {
  struct IterResult first = iterVec_peek(http);
  struct IterResult second;

  if (!first.status) {
    return ParseErr;
  }

  if (is_hexdig(first.ch)) {
    if (!h16_parse(http)) {
      return ParseErr;
    }

    for (int i = 0; i < 2; ++i) {
      first = iterVec_peek(http);
      second = iterVec_nth(http, 1);

      if (first.status && second.status && first.ch == ':' &&
          second.ch == ':') {
        break;
      }

      iterVec_next(http);

      if (!h16_parse(http)) {
        return ParseErr;
      }
    }
  }

  first = iterVec_next(http);
  second = iterVec_next(http);

  if (!first.status || !second.status || first.ch != ':' || second.ch != ':') {
    return ParseErr;
  }

  for (int i = 0; i < 2; ++i) {
    first = iterVec_peek(http);

    if (!first.status || !is_hexdig(first.ch)) {
      return ParseErr;
    }

    if (!h16_parse(http)) {
      return ParseErr;
    }

    first = iterVec_next(http);

    if (first.status && first.ch != ':') {
      return ParseErr;
    }
  }

  return ls32_parse(http);
}

enum ParseResult sixth(struct IterVec *http) {
  struct IterResult first = iterVec_peek(http);
  struct IterResult second;

  if (!first.status) {
    return ParseErr;
  }

  if (is_hexdig(first.ch)) {
    if (!h16_parse(http)) {
      return ParseErr;
    }

    for (int i = 0; i < 3; ++i) {
      first = iterVec_peek(http);
      second = iterVec_nth(http, 1);

      if (first.status && second.status && first.ch == ':' &&
          second.ch == ':') {
        break;
      }

      iterVec_next(http);

      if (!h16_parse(http)) {
        return ParseErr;
      }
    }
  }

  first = iterVec_next(http);
  second = iterVec_next(http);

  if (!first.status || !second.status || first.ch != ':' || second.ch != ':') {
    return ParseErr;
  }

  for (int i = 0; i < 1; ++i) {
    first = iterVec_peek(http);

    if (!first.status || !is_hexdig(first.ch)) {
      return ParseErr;
    }

    if (!h16_parse(http)) {
      return ParseErr;
    }

    first = iterVec_next(http);

    if (first.status && first.ch != ':') {
      return ParseErr;
    }
  }

  return ls32_parse(http);
}

enum ParseResult seventh(struct IterVec *http) {
  struct IterResult first = iterVec_peek(http);
  struct IterResult second;

  if (!first.status) {
    return ParseErr;
  }

  if (is_hexdig(first.ch)) {
    if (!h16_parse(http)) {
      return ParseErr;
    }

    for (int i = 0; i < 4; ++i) {
      first = iterVec_peek(http);
      second = iterVec_nth(http, 1);

      if (first.status && second.status && first.ch == ':' &&
          second.ch == ':') {
        break;
      }

      iterVec_next(http);

      if (!h16_parse(http)) {
        return ParseErr;
      }
    }
  }

  first = iterVec_next(http);
  second = iterVec_next(http);

  if (!first.status || !second.status || first.ch != ':' || second.ch != ':') {
    return ParseErr;
  }

  return ls32_parse(http);
}

enum ParseResult eigth(struct IterVec *http) {
  struct IterResult first = iterVec_peek(http);
  struct IterResult second;

  if (!first.status) {
    return ParseErr;
  }

  if (is_hexdig(first.ch)) {
    if (!h16_parse(http)) {
      return ParseErr;
    }

    for (int i = 0; i < 5; ++i) {
      first = iterVec_peek(http);
      second = iterVec_nth(http, 1);

      if (first.status && second.status && first.ch == ':' &&
          second.ch == ':') {
        break;
      }

      iterVec_next(http);

      if (!h16_parse(http)) {
        return ParseErr;
      }
    }
  }

  first = iterVec_next(http);
  second = iterVec_next(http);

  if (!first.status || !second.status || first.ch != ':' || second.ch != ':') {
    return ParseErr;
  }

  return h16_parse(http);
}

enum ParseResult ninth(struct IterVec *http) {
  struct IterResult first = iterVec_peek(http);
  struct IterResult second;

  if (!first.status) {
    return ParseErr;
  }

  if (is_hexdig(first.ch)) {
    if (!h16_parse(http)) {
      return ParseErr;
    }

    for (int i = 0; i < 6; ++i) {
      first = iterVec_peek(http);
      second = iterVec_nth(http, 1);

      if (first.status && second.status && first.ch == ':' &&
          second.ch == ':') {
        break;
      }

      iterVec_next(http);

      if (!h16_parse(http)) {
        return ParseErr;
      }
    }
  }

  first = iterVec_next(http);
  second = iterVec_next(http);

  if (!first.status || !second.status || first.ch != ':' || second.ch != ':') {
    return ParseErr;
  }

  return ParseOk;
}
