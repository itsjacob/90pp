class Solution
{
public:
  int mySqrt(int x)
  {
    if (x == 0) return 0;
    int left{ 1 };
    int right{ x };
    while (left <= right) {
      int mid = left + (right - left) / 2;
      int x1 = x / mid;
      if (x1 == mid) {
        left = mid + 1;
      } else if (x1 > mid) {
        left = mid + 1;
      } else if (x1 < mid) {
        right = mid - 1;
      }
    }
    return right;
  }
};
