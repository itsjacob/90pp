class Solution
{
public:
  vector<int> rearrangeBarcodes(vector<int> &barcodes)
  {
    // greedy algorithm, prioritize filling the most frequent number
    // 1. count the frequency of each number
    // 2. put all numbers in to a vector and sorted by their frequencies
    // 3.1 fill in all even positions with numbers with most frequencies
    // 3.2 if the fill position exceed the array size, rewind to fill position to 1
    // 3.3 fill in the rest numbers in odd positions

    std::unordered_map<int, int> frequencies;
    for (auto const &n : barcodes) {
      frequencies[n]++;
    }

    std::vector<std::pair<int, int>> sortedBarcodes;
    for (auto &item : frequencies) {
      sortedBarcodes.emplace_back(std::move(item));
    }
    std::sort(begin(sortedBarcodes), end(sortedBarcodes),
              [](pair<int, int> &p1, pair<int, int> &p2) { return p1.second > p2.second; });

    int pos{ 0 };
    std::vector<int> res(barcodes.size());
    for (auto &item : sortedBarcodes) {
      int num = item.first;
      int count = item.second;
      for (int ii = 0; ii < count; ii++) {
        if (pos >= barcodes.size()) pos = 1;
        res[pos] = num;
        pos += 2;
      }
    }
    return res;
  }
};
