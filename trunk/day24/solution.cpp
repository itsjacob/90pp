class Solution
{
public:
  int minSubarray(vector<int> &nums, int p)
  {
    // if the total sum modulus p is k
    // we can seprate the sum into two parts: a part that is dividable by p, and the other part modulus p is k
    // the problem basically translates into finding the smallest subarray,
    // whose sum modulus p is k
    // keyword: subarray, sum
    // it is most likely related to prefix sums
    // suppose we need to find a subarray [j+1, ..., i] such that (sum_i - sum_j) % p = k
    // this is a generalization of prefix sum problem, instead of have key := sum_i in the hashtable
    // we use key := sum_i % k in the hashtable
    // we only need to find if the key sum_i % p - k is available in the hastable

    long sum_all{ 0 };
    for (auto const &n : nums) {
      sum_all += n;
    }
    int sum_all_mod_p = sum_all % p;
    std::unordered_map<int, int> aMap;
    // Need to prepend the prefix sum array with sum value 0 and index -1, so that we can handle the first element
    aMap.emplace(0, -1);
    long sum_i{ 0 };
    int res = nums.size();
    for (int i = 0; i < nums.size(); i++) {
      sum_i += nums[i];
      int sum_i_mod_p = sum_i % p;
      // We can directly update this key,value pair because we are looking for smallest subarray
      aMap[sum_i_mod_p] = i;
      int sum_j_mod_p = sum_i_mod_p - sum_all_mod_p;
      // handle negative values of sum_j_mod_p
      if (sum_j_mod_p < 0) sum_j_mod_p += p;
      if (aMap.count(sum_j_mod_p) > 0) {
        res = std::min(res, i - aMap[sum_j_mod_p]);
      }
    }
    return res == nums.size() ? -1 : res;
  }
};
