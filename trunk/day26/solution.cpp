class Solution
{
public:
  int removeDuplicates(vector<int> &nums)
  {
    // O(1) space and O(n) time
    // The final array needs to be sorted, so we simply loop over the array
    // whenever we find a non-duplicate element, we copy to the front and increment the front index
    // can the slow pointer catch up with the faster pointer?
    // - no, because faster pointer walks at least one-step forward, the slow pointer walks at most one step
    //   and initially the faster pointer is one step ahead of the slow pointer
    if (nums.empty()) return 0;
    // i represents the first duplicate of the subarray
    int i{ 0 };
    while (i < nums.size() - 1 && nums[i + 1] != nums[i]) {
      i++;
    }
    // if (i == nums.size() - 1) return nums.size();
    // j represents the last duplicate of the subarray
    for (int j = i + 2; j < nums.size(); j++) {
      if (nums[j] != nums[j - 1]) {
        // 0,0,0,0,1,1,1,1,2
        // ^       ^
        // |       |
        // i       j
        // nums[j] is the last element of subarray which contains duplicates
        // copy it to the front
        nums[++i] = nums[j];
      }
    }
    return i + 1;
  }
};
