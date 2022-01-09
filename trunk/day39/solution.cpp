int mergeAndCount(std::vector<int> &nums, int beg, int mid, int end)
{
  // count the triple inversions
  int res{ 0 };
  for (int k = mid + 1, l = beg; k <= end; k++) {
    while (l <= mid && nums[l] <= 3 * nums[k]) {
      l++;
    }
    res += mid - l + 1;
  }

  // merge the two subarrays
  std::vector<int> tmp(end - beg + 1);
  int i{ beg };
  int j{ mid + 1 };
  int k{ 0 };
  while (i <= mid && j <= end) {
    if (nums[i] < nums[j]) {
      tmp[k++] = nums[i++];
    } else {
      tmp[k++] = nums[j++];
    }
  }
  while (i <= mid) {
    tmp[k++] = nums[i++];
  }
  while (j <= end) {
    tmp[k++] = nums[j++];
  }
  for (int ii = 0; ii < k; ii++) {
    nums[beg + ii] = tmp[ii];
  }
  return res;
}

int mergeSort(std::vector<int> &nums, int beg, int end)
{
  // - sort the array from beg to end inclusive
  // - return the triple inversions
  if (beg >= end) return 0;
  int mid = beg + (end - beg) / 2;
  int res = mergeSort(nums, beg, mid) + mergeSort(nums, mid + 1, end) + mergeAndCount(nums, beg, mid, end);
  return res;
}

int solve(vector<int> &nums)
{
  // Divide-and-conquer approach:
  // Suppose we know the triple inversion counts of two sorted subarrays
  // we then only need to add the number of triple inversions across the
  // two subarrays
  return mergeSort(nums, 0, nums.size() - 1);
}
