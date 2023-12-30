#ifndef GATE_REQUEST_H
#define GATE_REQUEST_H

#include "http/request/parse_result.h"
#include "method.h"

struct IterVec;
struct TrieNode;

struct Request {
  enum Method method;
};

/**
 * \brief Parse an HTTP request using the provided iterator.
 *
 * This function attempts to parse an HTTP request using the iterator
 * over the Vec structure, representing the HTTP content. It validates the
 * parsed HTTP method against the allowed methods stored in the TrieNode.
 *
 * @param http Pointer to the iterator over the Vec containing HTTP content.
 * @param request Pointer to the Request structure to store parsed data.
 * @param methods Pointer to the TrieNode storing allowed HTTP methods.
 * @return Returns a ParseResult enum representing the parsing outcome.
 *         'Ok' indicates successful parsing; other values may represent
 *         specific errors.
 */
enum ParseResult request_parse(struct IterVec *http, struct Request *request,
                               struct TrieNode *methods);

#endif // GATE_REQUEST_H
