class Solution
{

  class DisjointSet
  {
  private:
    std::vector<int> id;
    std::vector<int> sz;

    int find_recursive_(int x)
    {
      // path compression: flatten the uptree by pointing directly to the set id element
      if (id[x] != x) {
        id[x] = find_recursive_(id[x]);
      }
      return id[x];
    }

    int find_iterative_(int x)
    {
      while (id[x] != x) {
        // update id[x] to its grandparent, this is where the iterative log time complexity comes in
        // the tree height is decreased by a factor of 2
        id[x] = id[id[x]];
        x = id[x];
      }
      return id[x];
    }

  public:
    DisjointSet(int n)
    {
      id.resize(n);
      sz.resize(n);
      std::iota(id.begin(), id.end(), 0);
      std::fill(sz.begin(), sz.end(), 1);
    }

    // union is reserved keyword in cpp, so we rename it as unite
    void unite(int x, int y)
    {
      int xId = find(x);
      int yId = find(y);
      if (xId == yId) return;
      // smart union: merge smaller uptree onto bigger uptree
      if (sz[xId] < sz[yId]) {
        id[xId] = id[yId];
        sz[yId] += sz[xId];
      } else {
        id[yId] = id[xId];
        sz[xId] += sz[yId];
      }
      return;
    }

    int find(int x) { return find_recursive_(x); }

    bool connected(int x, int y) { return find(x) == find(y); }
  };

public:
  int findCircleNum(vector<vector<int>> &isConnected)
  {
    int n = isConnected.size();
    DisjointSet ds(n);

    // build the uptree
    for (int jj = 0; jj < n; jj++) {
      for (int ii = jj + 1; ii < n; ii++) {
        if (isConnected[jj][ii]) {
          ds.unite(jj, ii);
        }
      }
    }

    // ds.printDisjointSet();

    // count the id nodes from the uptrees
    int res{ 0 };
    for (int ii = 0; ii < n; ii++) {
      if (ds.find(ii) == ii) {
        res++;
      }
    }
    return res;
  }
};
