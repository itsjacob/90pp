class Solution
{
public:
  int numRescueBoats(vector<int> &people, int limit)
  {
    int maxWeight = *std::max_element(people.begin(), people.end());
    std::vector<int> weights(maxWeight + 1, 0);
    for (auto const &p : people) {
      weights[p]++;
    }
    int count{ 0 };
    for (auto const &p : people) {
      if (weights[p] != 0) {
        count++;
        weights[p]--;
        for (int left = std::min(limit - p, maxWeight); left > 0; left--) {
          if (weights[left] > 0) {
            weights[left]--;
            // at most 2 people on one boat, so we can break if we find two people
            break;
          }
        }
      }
    }
    return count;
  }
};
