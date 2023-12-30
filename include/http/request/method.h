#ifndef GATE_METHOD_H
#define GATE_METHOD_H

#include "http/request/parse_result.h"

struct IterVec;
struct TrieNode;
struct Request;

enum Method {
  GET,
  HEAD,
  POST,
  PUT,
  DELETE,
  CONNECT,
  OPTIONS,
  TRACE,
  PATCH,
};

/**
 * \brief Initializes the TrieNode structure for storing allowed HTTP methods.
 *
 * This function initializes the TrieNode structure to be used for storing
 * allowed HTTP methods. It sets up the TrieNode for method storage,
 * preparing it for method additions and lookups.
 *
 * @param trieNode Pointer to the TrieNode structure to be initialized.
 */
void methods_trieInit(struct TrieNode *trieNode);

/**
 * \brief Parses the HTTP method from the provided iterator and verifies if it's
 * allowed.
 *
 * This function parses the HTTP method from the iterator over the Vec
 * containing the HTTP request and checks whether the method is allowed based on
 * the provided TrieNode storing allowed methods.
 *
 * @param http Pointer to the iterator over the Vec containing the HTTP request.
 * @param request Pointer to the Request structure to store parsed data.
 * @param methods Pointer to the TrieNode storing allowed HTTP methods.
 * @return Returns a ParseResult enum indicating whether the parsed HTTP method
 * is allowed ('Ok' for allowed, 'Error' for disallowed or other specific
 * errors).
 */
enum ParseResult method_parse(struct IterVec *http, struct Request *request,
                              struct TrieNode *methods);

#endif // GATE_METHOD_H
