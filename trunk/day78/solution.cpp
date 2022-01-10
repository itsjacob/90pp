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
  };

public:
  int makeConnected(int n, vector<vector<int>> &connections)
  {

    // n computers at least need n-1 cables
    if (connections.size() < n - 1) {
      return -1;
    }

    // build the Disjoint set
    DisjointSet ds(n);
    for (auto const &c : connections) {
      ds.unite(c[0], c[1]);
    }

    // count the numbers of disjoint sets
    int res{ 0 };
    for (int ii = 0; ii < n; ii++) {
      if (ds.find(ii) == ii) {
        res++;
      }
    }

    // res is at most n

    // connecting res sets needs res-1 cables
    return res - 1;
  }
};
