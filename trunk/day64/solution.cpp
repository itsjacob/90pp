class Solution
{
public:
  int change(int amount, vector<int> &coins)
  {
    std::vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    // coin is the outer loop, meaning where can this coin contribute to?
    for (auto const &coin : coins) {
      for (int s = 0; s <= amount; s++) {
        if (s + coin > amount) continue;
        dp[s + coin] += dp[s];
      }
    }
    return dp[amount];
  }
};
