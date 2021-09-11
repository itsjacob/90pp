class Solution
{
  public:
    vector<int> shortestToChar(string s, char c)
    {
        // The shortest distance to c is eight from its left neighboring c or right neighboring c
        int n = s.length();
        vector<int> res(n, INT_MAX);

        // Sweep from left to right
        // When one c occurance is found, update its right neighors until the next occurance of c
        int cIdx = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == c) {
                cIdx = i;
            }
            if (cIdx != -1) {
                res[i] = i - cIdx;
            }
        }

        // Sweep from right to left
        // When one c occurance is found, update its left neighors until the next occurance of c
        cIdx = n;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == c) {
                cIdx = i;
            }
            if (cIdx != n) {
                res[i] = std::min(res[i], cIdx - i);
            }
        }

        return res;
    }
};
