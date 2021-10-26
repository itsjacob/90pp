class Solution
{

public:
  double new21Game(int n, int k, int maxPts)
  {
    // Original question is to find two cumulative distribution function F(k-1) and F(n) so that we can find
    // P(k <= x <= n) = F(n) - F(k-1) = sum[n] - sum[k-1]
    // let w = maxPts
    // each draw is in [1, w], so the probablity of total points equal to x, after the current draw is
    // the probablity of previous draw times the probability of current draw from [1, w]
    // Denote the marginal cumulative distribution function sum[i] as
    // sum[i] := P(0<=x<=i) = P(0<=x<=i-1) + P(i)  = sum[i-1] + P(i)
    // P(x) = (P(x-1) + P(x-2) + ... + P(0)) / w, for i <= w
    // P(x) = (P(x-1) + P(x-2) + ... + P(x-w)) / w, for x > w
    // =>
    // P(x) = sum[x-1] / w, for x <= w
    // P(x) = (sum[x-1] - sum[x-w-1]) / w, for x > w
    // sum[x] = sum[x-1] + P(x)

    // there's one more condition that one stops drawing after points reaches k (x >= k),
    // So when we compute P(x) for x > k, we can't have previous draw from [k, x-1], therefore, we deduct P(k<=i<=x-1)
    // from P(x), where P(k<=i<=x-1) = (sum[x-1] - sum[k-1])

    // initial condition sum[0] = 1.0 because we always start from 0 points
    // corner cases:
    // - k = 0, we can't draw anything, the total points is always <= n, so return 1.0
    // - n >= k -1 + w, we can at most get total points of k - 1 + w, so return 1.0

    if (k == 0 || n >= k - 1 + maxPts) return 1.0;
    std::vector<double> dp(k + maxPts, 0.0);
    dp[0] = 1.0;
    double p_i;
    for (int i = 1; i < k + maxPts; i++) {
      if (i <= maxPts) {
        p_i = dp[i - 1] / maxPts;
      } else {
        p_i = (dp[i - 1] - dp[i - maxPts - 1]) / maxPts;
      }
      if (i > k) {
        p_i -= (dp[i - 1] - dp[k - 1]) / maxPts;
      }
      dp[i] = dp[i - 1] + p_i;
    }
    return (dp[n] - dp[k - 1]);
  }
};

