#ifndef GATE_TRIE_H
#define GATE_TRIE_H

#define CHAR_SIZE 26

struct TrieNode;
struct IterVec;

enum TrieStatus {
  TrieSome,
  TrieNone,
};

struct TrieResult {
  enum TrieStatus trieStatus;
  void *val;
};

struct TrieNode {
  int is_end;
  void *val;
  struct TrieNode *children[CHAR_SIZE];
};

void trieNode_init(struct TrieNode *trieNode);

void trieNode_insert(struct TrieNode *root, const char *word, void *value);

struct TrieResult trieNode_searchIter(struct TrieNode *root,
                                      struct IterVec *iterVec);

void triNode_free(struct TrieNode *trieNode);

#endif // GATE_TRIE_H
