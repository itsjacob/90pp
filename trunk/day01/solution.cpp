class Solution
{
  public:
    std::vector<int> addToArrayForm(std::vector<int>& num, int k)
    {
        int carry = k;
        for (int i = num.size() - 1; i >= 0; i--) {
            int tmp = carry + num[i];
            carry = tmp / 10;
            num[i] = tmp % 10;
        }
        // Insert to the front at most 3 times
        while (carry > 0) {
            num.insert(num.begin(), carry % 10);
            carry /= 10;
        }
        return num;
    }
};
