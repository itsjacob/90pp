class Solution
{
public:
  // int lengthOfLongestSubstring(string s) {
  // std::unordered_map<char, int> aMap;
  // int p1{0};
  // int p2{0};
  // size_t res{0};
  // for (int ii = 0; ii < s.size(); ii++) {
  //   if (aMap.count(s[ii]) > 0) {
  //     int oldIdx = aMap[s[ii]];
  //     for (int jj = p1; jj <= oldIdx; jj++) {
  //       aMap.erase(s[jj]);
  //     }
  //     p1 = oldIdx + 1;
  //   }
  //   aMap.emplace(s[ii], p2);
  //   p2++;
  //   res = std::max(res, aMap.size());
  // }
  // return res;
  // }

  int lengthOfLongestSubstring(string s)
  {
    std::unordered_map<char, int> aMap;
    size_t lft{ 0 };
    size_t rht{ 0 };
    size_t res{ 0 };
    while (rht < s.size()) {
      char &rht_c = s[rht];
      rht++;
      if (aMap.count(rht_c) == 0) {
        aMap.emplace(rht_c, 1);
      } else {
        aMap[rht_c]++;
      }
      while (aMap[rht_c] > 1) {
        char &lft_c = s[lft];
        lft++;
        aMap[lft_c]--;
      }
      res = std::max(res, rht - lft);
    }
    return res;
  }
};
