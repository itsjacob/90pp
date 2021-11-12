class Solution
{
public:
  int coinChange(vector<int> &coins, int amount)
  {
    std::vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int s = 0; s <= amount; s++) {
      for (auto const &coin : coins) {
        if (coin > s) continue;
        dp[s] = std::min(dp[s], dp[s - coin] + 1);
      }
    }
    return dp[amount] == amount + 1 ? -1 : dp[amount];
  }
};
