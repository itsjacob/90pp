#define minOperations minOperations_slidingWindow
//#define minOperations minOperations_prefixSum
class Solution
{
public:
  int minOperations_slidingWindow(vector<int> &nums, int x)
  {
    int y = std::accumulate(nums.begin(), nums.end(), 0) - x;
    if (y < 0) return -1;

    int left{ 0 };
    int right{ 0 };
    int windowSum{ 0 };
    int res{ -1 };
    while (right < nums.size()) {
      int n1 = nums[right];
      right++;
      windowSum += n1;

      while (windowSum > y) {
        int n2 = nums[left];
        left++;
        windowSum -= n2;
      }

      if (windowSum == y) {
        res = std::max(res, right - left);
      }
    }

    return res == -1 ? -1 : nums.size() - res;
  }

  int minOperations_prefixSum(vector<int> &nums, int x)
  {
    // answer is from one of the followings:
    // - all elements from left
    // - all elements from right
    // - partial elements from left and partial elements from right
    // record two prefix sums, one is from left to right, and the other is from right to left
    // the prefix sums need to be in hashtable for contanst time look up doing two sums
    // nums is all positive, so the prefix sum is unique
    std::unordered_map<int, int> pSumLeft;
    std::unordered_map<int, int> pSumRight;
    int sumLeft{ 0 };
    int sumRight{ 0 };

    for (int ii = 0; ii < nums.size(); ii++) {
      sumLeft += nums[ii];
      pSumLeft.emplace(sumLeft, ii);
    }

    for (int ii = nums.size() - 1; ii >= 0; ii--) {
      sumRight += nums[ii];
      pSumRight.emplace(sumRight, ii);
    }

    std::vector<int> res;
    sumLeft = 0;
    for (int ii = 0; ii < nums.size(); ii++) {
      sumLeft += nums[ii];
      if (pSumRight.count(x - sumLeft)) {
        if (ii < pSumRight[x - sumLeft]) {
          res.push_back(ii + 1 + nums.size() - pSumRight[x - sumLeft]);
        }
      }
    }

    for (auto const &item : pSumLeft) {
      if (item.first == x) {
        res.push_back(item.second + 1);
      }
    }

    for (auto const &item : pSumRight) {
      if (item.first == x) {
        res.push_back(nums.size() - item.second);
      }
    }

    int minOps{ INT_MAX };
    std::for_each(res.begin(), res.end(), [&minOps](int &ii) {
      if (ii < minOps) minOps = ii;
    });
    return minOps == INT_MAX ? -1 : minOps;
  }
};
