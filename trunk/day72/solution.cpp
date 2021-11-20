class Solution
{
public:
  vector<vector<int>> subsets(vector<int> &nums)
  {
    // nums.length <= 10
    // use a 2-bytes short as a hashtable to mark if a subset has been seen before or not

    // a table of encoded vector of indices from the nums
    std::unordered_set<short> table;
    // backtrack helper variable to mark if num has been visted or not
    std::vector<bool> visited(nums.size(), false);
    std::vector<int> subvec;
    std::vector<std::vector<int>> res;

    backtrack(nums.size(), subvec, visited, table, res);

    // convert the indices into nums
    for (auto &subset : res) {
      for (auto &item : subset) {
        item = nums[item];
      }
    }
    return res;
  }

private:
  void backtrack(int n, std::vector<int> &subvec, std::vector<bool> &visited, std::unordered_set<short> &table,
                 std::vector<std::vector<int>> &res)
  {
    // serialize the subvec into a 2-bytes short
    short subvecCode = serialize(subvec);
    if (!table.count(subvecCode)) {
      table.emplace(subvecCode);
      res.emplace_back(subvec);
    }
    for (int ii = 0; ii < n; ii++) {
      if (visited[ii]) continue;
      visited[ii] = true;
      subvec.push_back(ii);
      backtrack(n, subvec, visited, table, res);
      visited[ii] = false;
      subvec.pop_back();
    }
    return;
  }

  inline short serialize(std::vector<int> &vec)
  {
    short code{ 0 };
    for (auto const &idx : vec) {
      code |= (1 << idx);
    }
    return code;
  }
};
