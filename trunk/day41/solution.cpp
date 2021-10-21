class Solution
{
public:
  int smallestDistancePair(vector<int> &nums, int k)
  {
    // The search space for the pair distance is [0, max{nums} - min{nums}]
    // the helper subroutine takes in a distance parameter and returns the number of pairs that is <= that parameter
    // the array needs to be sorted
    std::sort(nums.begin(), nums.end());
    int left{ 0 };
    int right = nums.back() - nums.front();
    while (left <= right) {
      int mid = left + (right - left) / 2;
      int nPairsBeforeMid = countDistancePairs(nums, mid);
      if (nPairsBeforeMid == k) {
        // Too many pairs, shrink the right side
        right = mid - 1;
      } else if (nPairsBeforeMid > k) {
        right = mid - 1;
      } else if (nPairsBeforeMid < k) {
        left = mid + 1;
      }
    }
    return left;
  }

private:
  /*
   * @return the number of distance pairs that is <= upperBound
   */
  int countDistancePairs(vector<int> &nums, int upperBound)
  {
    // two-pointer sliding window problem
    int fast{ 0 };
    int slow{ 0 };
    int res{ 0 };
    while (fast < nums.size()) {
      // fast sets the right boundary of the window
      // shrink the window if needed
      // the next j doesn't have to restart the slow pointer from 0
      // because if nums[j] - nums[slow] > upperBound, then nums[j+1] - nums[i] > upperBound for i <= slow
      while (nums[fast] - nums[slow] > upperBound) slow++;
      res += fast - slow;
      fast++;
    }
    return res;
  }
};
