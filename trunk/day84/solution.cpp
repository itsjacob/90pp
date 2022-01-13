class Solution
{
public:
  int strStr(string haystack, string needle)
  {
    // KMP solution in O(m+n) linear time as opposed to the brute-force O(mn) time
    return strStr_kmp(haystack, needle);
  }

private:
  void kmp(std::vector<std::vector<int>> &dfa, std::string pat)
  {
    // build the dfa lookup table for the pattern
    int constexpr R{ 256 }; // ASCII chars
    int m = pat.size();
    dfa[0][pat[0]] = 1;
    // memory state
    int x = 0;
    for (int j = 1; j < m; j++) {
      // char mismatch state transition rule
      // copy directly from memory state x
      for (int c = 0; c < R; c++) {
        dfa[j][c] = dfa[x][c];
      }
      // char match state transition rule
      // move to next state if match
      dfa[j][pat[j]] = j + 1;
      // move the memory state
      x = dfa[x][pat[j]];
    }
    return;
  }

  int strStr_kmp(string txt, string pat)
  {
    // KMP solution in O(m+n)
    if (pat.empty()) return 0;
    // create a dfa lookup table
    int n = txt.size();
    int m = pat.size();
    if (n < m) return -1;
    int constexpr R{ 256 }; // ASCII chars
    std::vector<std::vector<int>> dfa(m, std::vector<int>(R, 0));
    kmp(dfa, pat);

    // initial pattern state 0, state m indicates we find a match of pat in txt
    int j{ 0 };
    for (int i = 0; i < n; i++) {
      j = dfa[j][txt[i]];
      if (j == m) return i - m + 1;
    }
    return -1;
  }
};
