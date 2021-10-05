class Solution
{
public:
  vector<int> findSubstring(string s, vector<string> &words)
  {
    std::unordered_map<std::string, int> window;
    std::unordered_map<std::string, int> needed;
    for (auto &w : words) {
      if (needed.count(w) == 0) {
        needed.emplace(w, 1);
      } else {
        needed[w]++;
      }
    }

    std::vector<int> res;
    int wsize = words[0].size();
    int wordssize = wsize * words.size();
    for (int ii = 0; ii < wsize; ii++) {
      window.clear();
      int valid{ 0 };
      int left{ ii };
      int right{ ii };
      // cout << "wsize: " << wsize << " wordsize: " << wordssize << endl;
      while (right < s.size() - wsize + 1) {
        // Move faster pointer one step forward
        std::string rightStr = s.substr(right, wsize);
        right += wsize;
        // cout << "window: [" << left << ", " << right << ")" << endl;
        // Update the window if necessary
        if (needed.count(rightStr) > 0) {
          if (window.count(rightStr) == 0) {
            window.emplace(rightStr, 1);
          } else {
            window[rightStr]++;
          }
          if (window[rightStr] == needed[rightStr]) {
            valid++;
          }
          // cout << "   String to add: "<< rightStr <<  "， valid now: " << valid << endl;
        }
        // Try to shrink the window
        while (right - left >= wordssize) {
          if (valid == needed.size()) {
            res.push_back(left);
          }
          std::string leftStr = s.substr(left, wsize);
          left += wsize;
          if (needed.count(leftStr) > 0) {
            if (window[leftStr] == needed[leftStr]) {
              valid--;
            }
            window[leftStr]--;
          }
        }
      }
    }
    return res;
  }
};
