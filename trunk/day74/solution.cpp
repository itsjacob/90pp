// Using Trie with an extra field sum, sum is updated during insertion
class TrieNode
{
public:
  int val;
  int sum;
  TrieNode *nodes[26];
  TrieNode()
      : val{ 0 }
      , sum{ 0 }
  {
    for (auto &node : nodes) {
      node = nullptr;
    }
  }
};

class MapSum
{
private:
  TrieNode *root;

public:
  MapSum() { root = new TrieNode(); }

  void insert(string key, int val)
  {
    TrieNode *p = root;
    // Need to erase old val first
    for (auto const &c : key) {
      int idx = c - 'a';
      if (p->nodes[idx] == nullptr) {
        p->nodes[idx] = new TrieNode();
      }
      p = p->nodes[idx];
    }
    int oldVal = p->val;
    p = root;
    for (auto const &c : key) {
      int idx = c - 'a';
      p = p->nodes[idx];
      p->sum += val - oldVal;
    }
    p->val = val;
    return;
  }

  int sum(string prefix)
  {
    TrieNode *p = root;
    for (auto const &c : prefix) {
      int idx = c - 'a';
      if (p->nodes[idx] == nullptr) return 0;
      p = p->nodes[idx];
    }
    return p->sum;
  }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
