class Solution
{

  class DisjointSet
  {
  private:
    std::vector<int> id;
    std::vector<int> sz;

  public:
    DisjointSet(int n)
    {
      id.resize(n);
      sz.resize(n);
      std::iota(id.begin(), id.end(), 0);
      std::fill(sz.begin(), sz.end(), 1);
    }

    void unite(int x, int y)
    {
      int xId = find(x);
      int yId = find(y);
      if (xId == yId) return;
      if (sz[xId] < sz[yId]) {
        id[xId] = id[yId];
        sz[yId] += sz[xId];
      } else {
        id[yId] = id[xId];
        sz[xId] += sz[yId];
      }
      return;
    }

    int find(int x)
    {
      if (x != id[x]) {
        id[x] = find(id[x]);
      }
      return id[x];
    }

    int getSetSize(int x) { return sz[find(x)]; }
  };

public:
  int minMalwareSpread(vector<vector<int>> &graph, vector<int> &initial)
  {
    // build the uptree
    int n = graph.size();
    DisjointSet ds(n);
    for (int jj = 0; jj < n; jj++) {
      for (int ii = jj + 1; ii < n; ii++) {
        if (graph[jj][ii] == 1) {
          ds.unite(jj, ii);
        }
      }
    }

    // those initial computers belong to the same set can't be the answer, create a black list for them
    std::unordered_map<int, int> blacklist;
    for (auto const &ii : initial) {
      blacklist[ds.find(ii)]++;
    }

    int res = *std::min_element(initial.begin(), initial.end());
    int maxAffected = -1;
    for (auto const &ii : initial) {
      if (blacklist[ds.find(ii)] > 1) continue;
      int iiSize = ds.getSetSize(ii);
      if (iiSize > maxAffected) {
        res = ii;
        maxAffected = iiSize;
      } else if (iiSize == maxAffected && ii < res) {
        res = ii;
      }
    }

    return res;
  }
};
