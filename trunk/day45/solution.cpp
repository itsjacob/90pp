class Solution
{
public:
  vector<int> findAnagrams(string s, string p)
  {
    // p contains duplicated chars, so set is not enough
    int left{ 0 };
    int right{ 0 };
    int windowSize{ 0 };
    std::vector<int> res;
    std::unordered_map<char, int> matched;
    std::unordered_map<char, int> pTable;
    int matchedCount{ 0 };
    for (auto const &c : p) {
      pTable[c]++;
    }
    while (right < s.size()) {
      char c1 = s[right];
      right++;
      windowSize++;
      if (pTable.count(c1)) {
        matched[c1]++;
        if (pTable[c1] == matched[c1]) {
          matchedCount++;
        }
      }
      while (windowSize > p.size()) {
        char c2 = s[left];
        left++;
        windowSize--;
        if (pTable.count(c2)) {
          if (pTable[c2] == matched[c2]) {
            matchedCount--;
          }
          matched[c2]--;
        }
      }
      if (windowSize == p.size() && matchedCount == pTable.size()) {
        res.push_back(left);
      }
    }
    return res;
  }
};
