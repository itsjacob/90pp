class TrieNode
{
public:
  bool val;
  TrieNode *nodes[26];

  TrieNode()
      : val{ false }
  {
    for (auto &node : nodes) {
      node = nullptr;
    }
  }
};

class Trie
{
private:
  TrieNode *root;

public:
  Trie() { root = new TrieNode(); }

  void insert(string word)
  {
    TrieNode *p = root;
    for (auto const &c : word) {
      int idx = c - 'a';
      // if the char has null link, we create it first
      if (p->nodes[idx] == nullptr) {
        p->nodes[idx] = new TrieNode();
      }
      p = p->nodes[idx];
    }
    p->val = true;
    return;
  }

  bool search(string word)
  {
    TrieNode *p = root;
    // Walk down the word char by char, early break with false if encountered with null links
    for (auto const &c : word) {
      int idx = c - 'a';
      if (p->nodes[idx] == nullptr) return false;
      p = p->nodes[idx];
    }
    // Reached the wanted node
    return p->val;
  }

  bool startsWith(string prefix)
  {
    TrieNode *p = root;
    for (auto const &c : prefix) {
      int idx = c - 'a';
      if (p->nodes[idx] == nullptr) return false;
      p = p->nodes[idx];
    }
    // all chars in the prefix has valid links, so the prefix exist in the trie
    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
