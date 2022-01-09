class Solution
{
public:
  string minWindow(string s, string t)
  {
    std::unordered_map<char, int> tTable;
    for (auto const &c : t) {
      tTable[c]++;
    }

    int left{ 0 };
    int right{ 0 };
    int matchedCount{ 0 };
    std::unordered_map<char, int> matched;
    std::string res;

    while (right < s.size()) {
      char c1 = s[right];
      right++;
      if (tTable.count(c1)) {
        matched[c1]++;
        if (matched[c1] == tTable[c1]) {
          matchedCount++;
        }
      }

      while (matchedCount == tTable.size()) {
        char c2 = s[left];
        if (tTable.count(c2)) {
          if (matched[c2] == tTable[c2]) {
            // we can't shrink window, if we do, the window is not valid anymore
            // record current window
            if (res.empty() || right - left < res.size()) {
              res = s.substr(left, right - left);
            }
            break;
          } else {
            matched[c2]--;
            left++;
          }
        } else {
          left++;
        }
      }
    }
    return res;
  }
};
