class Solution
{
public:
  int findContentChildren(vector<int> &g, vector<int> &s)
  {
    std::sort(g.begin(), g.end());
    std::sort(s.begin(), s.end());
    int i{ 0 };
    int j{ 0 };
    int res{ 0 };
    // Notice each element in the cookie array can only be assigned to one child
    while (i < g.size() && j < s.size()) {
      if (s[j] >= g[i]) {
        res++;
        // s[j] -= g[i];
        j++;
        i++;
      } else {
        j++;
      }
    }
    return res;
  }
};
