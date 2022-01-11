class Solution
{
public:
  string frequencySort(string s)
  {
    // hashtable to count the frequency first
    std::unordered_map<char, int> aMap;
    for (auto const &c : s) {
      aMap[c] += 1;
    }
    // the max count of a char is the length of the string
    std::vector<std::vector<char>> aVec(s.size() + 1, std::vector<char>());
    for (auto const &elem : aMap) {
      aVec[elem.second].push_back(elem.first);
    }

    std::string res;
    for (int ii = s.size(); ii >= 0; ii--) {
      if (!aVec[ii].empty()) {
        for (auto const &c : aVec[ii]) {
          for (int jj = 0; jj < ii; jj++) {
            res += c;
          }
        }
      }
    }
    return res;
  }
};
