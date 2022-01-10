class Solution
{
public:
  int findKthLargest(vector<int> &nums, int k)
  {
    // return findKthLargest_minHeap(nums, k);
    return findKthLargest_quickselect(nums, k);
  }

  int findKthLargest_minHeap(vector<int> &nums, int k)
  {
    // minheap will contain the k largest values with k-th element on the top
    // O(k) to create a minheap
    // O((n-k) * logk) to loop over all the rest
    std::vector<int> knums;
    auto comp = [](int n1, int n2) { return n1 > n2; };

    for (auto const &n : nums) {
      if (knums.size() < k) {
        knums.push_back(n);
        if (knums.size() == k) {
          std::make_heap(begin(knums), end(knums), comp);
        }
        continue;
      }
      if (n > knums.front()) {
        std::pop_heap(begin(knums), end(knums), comp);
        knums.pop_back();

        knums.push_back(n);
        std::push_heap(begin(knums), end(knums), comp);
      }
    }
    return knums.front();
  }

  int partition(vector<int> &nums, int lo, int hi)
  {
    int random_idx = rand() % (hi - lo + 1) + lo;
    swap(nums[lo], nums[random_idx]);
    int pivot = nums[lo];
    int l = lo + 1;
    int r = hi;
    while (l <= r) {
      if (nums[l] > pivot && nums[r] < pivot) {
        swap(nums[l++], nums[r--]);
      }
      if (nums[l] <= pivot) l++;
      if (nums[r] >= pivot) r--;
    }
    swap(nums[lo], nums[r]);
    return r;
  }

  int findKthLargest_quickselect(vector<int> &nums, int k)
  {
    // mix of binary search and partition function of quick sort
    k = nums.size() - k;
    int lo = 0;
    int hi = nums.size() - 1;
    while (lo <= hi) {
      int pos = partition(nums, lo, hi);
      if (pos == k)
        return nums[pos];
      else if (pos < k)
        lo = pos + 1;
      else if (pos > k)
        hi = pos - 1;
    }
    return -1;
  }
};
