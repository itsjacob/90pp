class Solution
{
public:
  vector<int> singleNumber(vector<int> &nums)
  {
    // - bit xor operation is commutative, ie.,
    //   a ^ b ^ c ^ d ^ a ^ b = a ^ a ^ b ^ b ^ c ^ d = (a ^ a) ^ (b ^ b) ^ c ^ d
    // - xor of same numbers resets all bits to zero, ie.,
    //   a ^ a = 0
    // - zero xor any number is that number itself, ie., 0 ^ c = c

    // suppose c and d are the different numbers that only appear once
    // step 1: variable twoNums will have two non-zero bits that represent the two numbers
    int twoNums{ 0 };
    std::for_each(nums.begin(), nums.end(), [&twoNums](int &num) { twoNums ^= num; });

    // step 2: create a one-bit mask that can be used later to tell apart the two numbers
    int mask{ 1 };
    while ((mask & twoNums) == 0) {
      mask = mask << 1;
    }

    // step 3: variable mask is used to segment the two different numbers, same num will go to same category twice
    std::vector<int> res(2, 0);
    for (auto const &num : nums) {
      if ((num & mask)) {
        res[0] ^= num;
      } else {
        res[1] ^= num;
      }
    }
    return res;
  }
};
