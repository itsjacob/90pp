class Solution
{

public:
  vector<string> readBinaryWatch(int turnedOn)
  {
    std::vector<string> res;
    std::vector<int> leds = { -1, -2, -4, -8, 1, 2, 4, 8, 16, 32 };
    std::vector<bool> visited(10, false);
    int hh{ 0 };
    int mm{ 0 };
    int nVisited{ 0 };
    backtrack(res, leds, turnedOn, visited, nVisited, hh, mm);
    // Sort and then remove duplicates
    std::sort(res.begin(), res.end());
    res.erase(std::unique(res.begin(), res.end()), res.end());
    return res;
  }

private:
  inline static std::string convertTimeToString(int hh, int mm)
  {
    char time[8];
    sprintf(time, "%d:%02d", -hh, mm);
    return std::string(time);
  }

  void backtrack(std::vector<string> &res, std::vector<int> &leds, int turnedOn, std::vector<bool> &visited,
                 int &nVisited, int &hh, int &mm)
  {
    if (nVisited == turnedOn) {
      if (hh >= -11 && mm <= 59) {
        res.emplace_back(convertTimeToString(hh, mm));
      }
      return;
    }

    for (int ii = 0; ii < leds.size(); ii++) {
      if (visited[ii]) continue;

      // select the choice
      int led = leds[ii];
      if (led < 0) {
        hh += led;
      } else {
        mm += led;
      }
      nVisited++;
      visited[ii] = true;

      // One more depth to backtrack
      backtrack(res, leds, turnedOn, visited, nVisited, hh, mm);

      // Cancel out the choice
      visited[ii] = false;
      nVisited--;
      if (led < 0) {
        hh -= led;
      } else {
        mm -= led;
      }
    }
  }
};
