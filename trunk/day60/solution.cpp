class Solution
{
public:
  bool canIWin(int maxChoosableInteger, int desiredTotal)
  {
    // define a state as boolean values for each int in [1, maxChoosableInteger]
    // encode them into a 32-bits int, each bit represents the chosen/or not chosen status of the int
    // maxChoosableInteger <= 20, so 32-bits int is enough for the state
    // bracktrack + dp with bottom-up memoization
    if (desiredTotal <= maxChoosableInteger) return true;
    if ((1 + maxChoosableInteger) * 0.5 * maxChoosableInteger < desiredTotal) return false;
    std::unordered_map<int, bool> dp;
    int state{ 0 };
    return dfs(maxChoosableInteger, desiredTotal, state, dp);
  }

private:
  bool dfs(int maxChoosableInteger, int desiredTotal, int state, std::unordered_map<int, bool> &dp)
  {
    if (dp.count(state)) return dp[state];
    for (int ii = 1; ii <= maxChoosableInteger; ii++) {
      int maskOfTheInt = (1 << (ii - 1));
      if (state & maskOfTheInt) continue;
      // I will select ii, can I win now?
      bool iCanWin = (desiredTotal <= ii);
      // select the option: I choose to use ii, can you win?
      bool youCanWin = dfs(maxChoosableInteger, desiredTotal - ii, state | maskOfTheInt, dp);
      if (iCanWin || !youCanWin) {
        dp[state] = true;
        // we don't have to do the unselect as we select the state on-the-fly with pass by value to next call
        return true;
      }
    }
    // if I haven't returned from the loop, then I didn't win after looping over all the ints
    dp[state] = false;
    return false;
  }
};
