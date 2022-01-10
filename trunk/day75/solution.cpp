class TrieNode
{
public:
  int val;
  TrieNode *nodes[26];
  TrieNode()
      : val{ -1 }
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

  void insert(std::string const key, int val)
  {
    TrieNode *p = root;
    for (auto const &c : key) {
      int idx = c - 'a';
      if (p->nodes[idx] == nullptr) {
        p->nodes[idx] = new TrieNode();
      }
      p = p->nodes[idx];
    }
    p->val = val;
  }

  void search(vector<vector<int>> &res, string const &prefix, int sid)
  {
    TrieNode *p = root;
    for (auto const &c : prefix) {
      int idx = c - 'a';
      if (p->nodes[idx] == nullptr) return;
      if (p->nodes[idx]->val != -1) {
        // found one small in the Trie for the given prefix
        res[p->nodes[idx]->val].push_back(sid);
      }
      p = p->nodes[idx];
    }
  }
};

class Solution
{
public:
  vector<vector<int>> multiSearch(string big, vector<string> &smalls)
  {
    // Construct the prefix tree from smalls
    Trie myTrie;
    for (int ii = 0; ii < smalls.size(); ii++) {
      myTrie.insert(smalls[ii], ii);
    }
    // search each substring of big in the built Trie
    // if found record the substring into the proper position (located by the val of the node)
    std::vector<std::vector<int>> res(smalls.size(), std::vector<int>());
    for (int ii = 0; ii < big.size(); ii++) {
      string subBig = big.substr(ii, big.size() - ii);
      myTrie.search(res, subBig, ii);
    }
    return res;
  }
};
