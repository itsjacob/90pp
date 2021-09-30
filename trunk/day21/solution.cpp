class Solution
{
public:
  int numberOfBoomerangs(vector<vector<int>> &points)
  {
    auto distSquare = [](std::vector<int> &p1, std::vector<int> &p2) -> int {
      return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    };
    // hashtables
    std::unordered_map<int, int> aMap;
    int res{ 0 };
    for (int ii = 0; ii < points.size(); ii++) {
      // Add all the qualified ones to the map
      for (int jj = 0; jj < points.size(); jj++) {
        if (ii == jj) continue;
        int dist = distSquare(points[ii], points[jj]);
        if (aMap.count(dist) == 0) {
          aMap.emplace(dist, 1);
        } else {
          aMap[dist]++;
        }
      }
      // Count the permutations
      for (const auto &m : aMap) {
        if (m.second > 1) {
          res += m.second * (m.second - 1);
        }
      }
      aMap.clear();
    }
    return res;
  }
};
