class Solution
{
public:
  vector<int> beautifulArray(int n)
  {
    // backtrack is too slow because testing for the beautiful array is O(n^2)
    // divide-and-conquer solution: if an array statisfies the second property of beautiful array
    // - scaling each number in the array still honors the same property
    // - adding a constant to the array still honors the property
    // notice any number can be boostraped from 2*n-1 or 2*n, starting from a single number 1
    //
    std::vector<int> res{ 1 };
    while (res.size() < n) {
      std::vector<int> tmp;
      for (auto const &num : res) {
        int odd = num * 2 - 1;
        if (odd <= n) {
          tmp.push_back(odd);
        }
      }
      for (auto const &num : res) {
        int even = num * 2;
        if (even <= n) {
          tmp.push_back(even);
        }
      }
      res = tmp;
    }
    return res;
  }
};
