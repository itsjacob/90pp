#define sortArray_ countingSort
class Solution
{
public:
  vector<int> sortArray(vector<int> &nums) { return sortArray_(nums); }

private:
  std::vector<int> countingSort(std::vector<int> &nums)
  {
    std::vector<int> res;
    int constexpr MIN_VAL{ -50000 };
    int constexpr MAX_VAL{ 50000 };
    std::vector<int> countTable(MAX_VAL - MIN_VAL + 1, 0);
    for (auto const &num : nums) {
      countTable[num - MIN_VAL]++;
    }

    for (int ii = 0; ii < countTable.size(); ii++) {
      if (countTable[ii] == 0) continue;
      // record current number count times
      for (int jj = 0; jj < countTable[ii]; jj++) {
        res.push_back(ii + MIN_VAL);
      }
    }
    return res;
  }
};
