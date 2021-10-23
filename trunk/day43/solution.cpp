class Solution
{
public:
  int maxVowels(string s, int k)
  {
    int left{ 0 };
    int right{ 0 };
    int count{ 0 };
    int res{ 0 };
    int nVowels{ 0 };

    std::unordered_set<char> vowelsTable;
    for (char const &c : "aeiou") {
      vowelsTable.emplace(c);
    }

    while (right < s.size()) {
      char c1 = s[right];
      right++;
      count++;
      if (vowelsTable.count(c1)) {
        nVowels++;
      }

      while (count > k) {
        char c2 = s[left];
        left++;
        count--;
        if (vowelsTable.count(c2)) {
          nVowels--;
        }
      }

      if (count == k) {
        res = std::max(res, nVowels);
      }
    }
    return res;
  }
};
