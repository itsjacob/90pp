class Solution
{
public:
  int minCharacters(string a, string b)
  {
    // count the operations for each case and select the mininum of them
    std::vector<int> res;
    std::vector<int> aLetterTable(26, 0);
    for (auto const &c : a) {
      aLetterTable[c - 'a']++;
    }

    std::vector<int> bLetterTable(26, 0);
    for (auto const &c : b) {
      bLetterTable[c - 'a']++;
    }

    auto countAGreaterThanB = [](std::vector<int> &aTable, std::vector<int> &bTable) -> int {
      int res{ INT_MAX };
      // Set the pivot char as 'a'+ii
      for (int ii = 1; ii < 26; ii++) {
        int count{ 0 };
        // Find in string a how many chars are < 'a'+ii, so that we can modify them as 'a'+ii+1
        for (int jj = 0; jj < ii; jj++) {
          count += aTable[jj];
        }
        // Find in string b how many chars are >= 'a'+ii, so that we can modify them as 'a'+ii-1
        // Notice the outer loop starts from 1 because we need to modify the found chars in b to be 'a'+ii-1
        for (int jj = ii; jj < 26; jj++) {
          count += bTable[jj];
        }
        res = std::min(count, res);
      }
      return res;
    };
    res.push_back(countAGreaterThanB(aLetterTable, bLetterTable));
    res.push_back(countAGreaterThanB(bLetterTable, aLetterTable));

    // Case 3
    int aLetterMaxCount = *std::max_element(aLetterTable.begin(), aLetterTable.end());
    int bLetterMaxCount = *std::max_element(bLetterTable.begin(), bLetterTable.end());
    res.push_back(a.size() + b.size() - aLetterMaxCount - bLetterMaxCount);

    return *std::min_element(res.begin(), res.end());
  }
};
