class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    std::unordered_map<int, int> aMap;
    std::vector<int> res;
    for (int ii = 0; ii < nums.size(); ii++) {
      if (aMap.count(target - nums[ii]) > 0) {
        res.push_back(ii);
        res.push_back(aMap[target - nums[ii]]);
        break;
      } else {
        aMap.emplace(nums[ii], ii);
      }
    }
    return res;
  }
};
