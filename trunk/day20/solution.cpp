class Solution
{
public:
  vector<int> topKFrequent(vector<int> &nums, int k)
  {
    // The top k problems are solved by heaps, we need minimum heap to store most frequent elements
  std:
    vector<int> res;
    // pair<count, n>
    std::vector<std::pair<int, int>> aVec;
    auto comp = [](std::pair<int, int> &p1, std::pair<int, int> &p2) { return p1.second > p2.second; };

    // First pass to count the frequencies of nums
    // key,val = num, count
    std::unordered_map<int, int> aMap;
    for (auto const &n : nums) {
      if (aMap.count(n) > 0) {
        aMap[n]++;
      } else {
        aMap.emplace(n, 1);
      }
    }

    // All std::make_heap, std::push_heap, std::push_heap need to use comparator to work with min heap
    // min heap of size k to store the most k frequent elements
    for (auto const &m : aMap) {
      if (aVec.size() < k) {
        aVec.emplace_back(std::move(m));
        if (aVec.size() == k) {
          std::make_heap(aVec.begin(), aVec.end(), comp);
        }
        continue;
      }
      if (aVec.front().second < m.second) {
        // Remove the least frequent element from the heap
        std::pop_heap(aVec.begin(), aVec.end(), comp);
        aVec.pop_back();

        aVec.emplace_back(std::move(m));
        std::push_heap(aVec.begin(), aVec.end(), comp);
      }
    }

    for (auto const &p : aVec) {
      res.push_back(p.first);
    }

    return res;
  }
};
