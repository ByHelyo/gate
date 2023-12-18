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
  int value;
};

struct TrieNode {
  int is_end;
  int value;
  struct TrieNode *children[CHAR_SIZE];
};

/**
 * \brief Initializes a TrieNode structure.
 *
 * This function initializes the TrieNode structure for use in storing data.
 *
 * @param trieNode Pointer to the TrieNode structure to be initialized.
 */
void trieNode_init(struct TrieNode *trieNode);

/**
 * \brief Inserts a word and its associated value into the TrieNode structure.
 *
 * Inserts a word and its corresponding value into the TrieNode structure
 * starting from the root node.
 *
 * @param root Pointer to the root TrieNode of the structure.
 * @param word The word to be inserted into the Trie.
 * @param value The value associated with the word to be stored.
 */
void trieNode_insert(struct TrieNode *root, const char *word, int value);

/**
 * \brief Searches for a word in the TrieNode structure using an iterator.
 *
 * Searches for a word in the TrieNode structure using an iterator over the Vec
 * containing the word's characters.
 *
 * @param root Pointer to the root TrieNode of the structure.
 * @param iterVec Pointer to the iterator over the Vec containing characters of
 * the word.
 * @return Returns a TrieResult structure indicating the search result.
 */
struct TrieResult trieNode_searchIter(struct TrieNode *root,
                                      struct IterVec *iterVec);

/**
 * \brief Frees memory associated with the TrieNode structure.
 *
 * Frees memory allocated for the TrieNode structure and its associated data.
 *
 * @param trieNode Pointer to the TrieNode structure to be freed.
 */
void triNode_free(struct TrieNode *trieNode);

#endif // GATE_TRIE_H
