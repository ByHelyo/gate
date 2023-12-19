#include "http/request/method.h"

#include "misc/trie/trie.h"
#include "misc/vector/iter.h"

void methods_trieInit(struct TrieNode *trieNode) { // TODO : error insert trie
  trieNode_init(trieNode);

  trieNode_insert(trieNode, "GET", GET);
  trieNode_insert(trieNode, "HEAD", HEAD);
  trieNode_insert(trieNode, "POST", POST);
  trieNode_insert(trieNode, "PUT", PUT);
  trieNode_insert(trieNode, "DELETE", DELETE);
  trieNode_insert(trieNode, "CONNECT", CONNECT);
  trieNode_insert(trieNode, "OPTIONS", OPTIONS);
  trieNode_insert(trieNode, "TRACE", TRACE);
  trieNode_insert(trieNode, "PATCH", PATCH);
}

enum ParseResult method_parse(struct IterVec *http, struct TrieNode *methods) {
  struct TrieResult trieResult = trieNode_searchIter(methods, http);

  if (trieResult.trieStatus == TrieNone) {
    return ParseErr;
  }

  return ParseOk;
}
