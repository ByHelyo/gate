#ifndef GATE_PARSE_RESULT_H
#define GATE_PARSE_RESULT_H

/**
 * @enum ParseResult
 * \brief Represents different parsing outcomes during HTTP request parsing.
 *
 * This enumeration defines potential outcomes that might arise
 * during the parsing of an HTTP request using the request_parse function.
 */
enum ParseResult {
  ParseErr,
  ParseOk,
};

#endif // GATE_PARSE_RESULT_H
