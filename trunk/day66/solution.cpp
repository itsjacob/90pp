class Solution
{
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals)
  {
    if (intervals.size() <= 1) return 0;
    std::sort(intervals.begin(), intervals.end(),
              [](vector<int> &i1, vector<int> &i2) { return i1[0] < i2[0] || (i1[0] == i2[0] && i1[1] < i2[1]); });
    // for vi and vj in intervals
    // case 1:
    //   contains:
    //     - vi contains vj, remove vi, i = j, j++
    //     - vj contains vi, remove vj, j++
    // case 2:
    //    overlap: remove latter (vj), j++, we remove latter because vj might overlap with vj+1
    // case 3:
    //    non-overlap: i = j, j++
    int i{ 0 };
    int j{ 1 };
    int count{ 0 };
    while (j < intervals.size()) {
      auto &vi = intervals[i];
      auto &vj = intervals[j];
      if (vi[0] <= vj[0] && vi[1] >= vj[1]) {
        // case 1.1: vi contains vj
        i = j;
        j++;
        count++;
      } else if (vi[0] >= vj[0] && vi[1] <= vj[1]) {
        // case 1.2: vj contains vi
        j++;
        count++;
      } else if (vi[1] > vj[0]) {
        // case 2: vi partially overlaps with vj
        // always remove vj because there's a possibility vj will overlap with vj+1
        j++;
        count++;
      } else {
        // case 3: vi has no overlap with vj
        i = j;
        j++;
      }
    }
    return count;
  }
};
