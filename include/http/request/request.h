#ifndef GATE_REQUEST_H
#define GATE_REQUEST_H

struct IterVec;

/**
 * @enum ParseResult
 * \brief Represents different parsing outcomes during HTTP request parsing.
 *
 * This enumeration defines potential outcomes that might arise
 * during the parsing of an HTTP request using the request_parse function.
 */
enum ParseResult {
  Ok,
};

/**
 * \brief Parse an HTTP request from the given iterator.
 *
 * This function attempts to parse an HTTP request using the provided iterator
 * over the Vec structure, which represents the HTTP content.
 *
 * @param http Pointer to the iterator over the Vec containing HTTP content.
 * @return Returns an instance of ParseResult representing the parsing outcome.
 *         'Ok' indicates successful parsing; other values may represent
 * specific errors.
 */
enum ParseResult request_parse(struct IterVec *http);

#endif // GATE_REQUEST_H
