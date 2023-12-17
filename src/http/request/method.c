#include "http/request/method.h"

#include "misc/trie/trie.h"
#include "misc/vector/iter.h"
#include <stdio.h>
enum ParseResult method_parse(struct IterVec *http) {
  struct IterResult ret = iterVec_peek(http);
  if (ret.status == IterNone) {
    return ParseErr;
  }

  struct TrieNode trieNode;
  trieNode_init(&trieNode);
  trieNode_insert(&trieNode, "HELLO");
  printf("%i\n", trieNode_searchIter(&trieNode, http));

  return ParseOk;
}
