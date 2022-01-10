class Solution
{
public:
  int lastStoneWeight(vector<int> &stones)
  {
    std::make_heap(stones.begin(), stones.end());
    while (stones.size() > 1) {
      auto stone1 = stones.front();
      std::pop_heap(stones.begin(), stones.end());
      stones.pop_back();
      auto stone2 = stones.front();
      std::pop_heap(stones.begin(), stones.end());
      stones.pop_back();
      if (stone1 != stone2) {
        stones.push_back(stone1 - stone2);
        std::push_heap(stones.begin(), stones.end());
      }
    }
    int res{ 0 };
    if (!stones.empty()) {
      res = stones.front();
    }
    return res;
  }
};
