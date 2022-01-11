class Solution
{
public:
  int kthSmallest(vector<vector<int>> &matrix, int k)
  {
    // max heap, flatten the matrix, space complexity O(k) = O(n^2)
    // need more memory-efficient: binary search
    int left = matrix[0][0];
    int right = matrix[matrix.size() - 1][matrix[0].size() - 1];
    while (left < right) {
      int mid = left + (right - left) / 2;
      // count how many elements in each row are less than mid, then accumulate
      int nElemLessThanMid{ 0 };
      for (int ii = 0; ii < matrix.size(); ii++) {
        nElemLessThanMid += std::upper_bound(begin(matrix[ii]), end(matrix[ii]), mid) - matrix[ii].begin();
      }
      if (nElemLessThanMid < k) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    // loop quite with left == right
    return left;
  }
};
