bool areHousesLitUp(vector<int> &nums, int diameter)
{
  // Given the array, 3 lights, and a diameter, can they light all houses up?
  int constexpr TOTAL_LIGHTS_NUM{ 3 };
  int end = nums[0] + diameter;
  int count{ 0 };
  for (auto const &num : nums) {
    if (num > end) {
      count++;
      end = num + diameter;
    }
  }
  return count < TOTAL_LIGHTS_NUM;
}

double solve(vector<int> &nums)
{
  // binary search for the diameter, with search range 0 ~ nums.max_value 
  // left-bound binary search
  if (nums.size() <= 3) return 0.0;
  std::sort(std::begin(nums), std::end(nums));
  int left = 0;
  int right = nums.back();
  while (left <= right) {
    double mid = left + (right - left) / 2;
    if (areHousesLitUp(nums, mid)) {
      // shrink the right boundary
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return left * 0.5;
}
