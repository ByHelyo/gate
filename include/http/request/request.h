#ifndef GATE_REQUEST_H
#define GATE_REQUEST_H

#include <misc/vector/iter.h>

/**
 * @enum ParseError
 * \brief Represents different parsing errors during HTTP request parsing.
 *
 * This enumeration defines potential error types that might occur
 * during the parsing of an HTTP request using request_parse function.
 */
enum ParseError {
  Ok,
};

/**
 * \brief Parse an HTTP request from the given iterator.
 *
 * This function attempts to parse an HTTP request using the provided iterator
 * over the Vec structure, representing the HTTP content.
 *
 * @param http Pointer to the iterator over the Vec containing HTTP content.
 * @return Returns an instance of ParseError representing the parsing result.
 *         Ok indicates successful parsing; other values represent specific
 * errors.
 */
enum ParseError request_parse(struct IterVec *http);

#endif // GATE_REQUEST_H
