#include "misc/trie/trie.h"

#include "logger/log.h"

#include <errno.h>
#include <misc/vector/iter.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

void trieNode_init(struct TrieNode *trieNode) {
  for (size_t i = 0; i < CHAR_SIZE; ++i) {
    trieNode->children[i] = NULL;
  }
  trieNode->is_end = 0;
}

struct TrieNode *trieNode_build(void) {
  struct TrieNode *trieNode = calloc(1, sizeof(struct TrieNode));

  if (trieNode == NULL) {
    log_error("allocation of TrieNode failed: %s", strerror(errno));
    return NULL;
  }

  trieNode_init(trieNode);
  return trieNode;
}

void trieNode_insert(struct TrieNode *root, const char *word) {
  struct TrieNode *cur = root;

  for (size_t i = 0; word[i] != '\0'; ++i) {
    int letter_idx = word[i] - 'A';

    if (cur->children[letter_idx] == NULL) {
      cur->children[letter_idx] = trieNode_build();
    }

    cur = cur->children[letter_idx];
  }

  cur->is_end = 1;
}

enum TrieResult trieNode_searchIter(struct TrieNode *root,
                                    struct IterVec *iterVec) {
  struct TrieNode *cur = root;

  while (1) {
    struct IterResult ret = iterVec_peek(iterVec);

    if (ret.status == IterNone) {
      return TrieNone;
    }

    if (ret.ch < 'A' || ret.ch > 'Z') {
      break;
    }

    int letter_idx = ret.ch - 'A';
    if (cur->children[letter_idx] == NULL) {
      return TrieNone;
    }

    cur = cur->children[letter_idx];
  }

  if (cur->is_end) {
    return TrieNone;
  }
  return TrieNone;
}

void triNode_free(struct TrieNode *trieNode) {
  if (trieNode == NULL) {
    return;
  }

  for (size_t i = 0; i < CHAR_SIZE; ++i) {
    triNode_free(trieNode->children[i]);
    trieNode->children[i] = NULL;
  }

  free(trieNode);
}
