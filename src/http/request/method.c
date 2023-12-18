#include "http/request/method.h"
#include <stdio.h>

#include "misc/trie/trie.h"
#include "misc/vector/iter.h"

enum ParseResult method_parse(struct IterVec *http) {
  struct IterResult ret = iterVec_peek(http);
  if (ret.status == IterNone) {
    return ParseErr;
  }

  struct TrieNode trieNode;
  trieNode_init(&trieNode);
  trieNode_insert(&trieNode, "HELLO", NULL);
  printf("%i\n", trieNode_searchIter(&trieNode, http).trieStatus);
  printf("%i\n", trieNode_searchIter(&trieNode, http).trieStatus);

  return ParseOk;
}
