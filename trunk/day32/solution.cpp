class Solution
{
public:
  bool judgeCircle(string moves)
  {
    int x{ 0 };
    int y{ 0 };
    for (auto const &c : moves) {
      if (c == 'U') {
        y++;
      } else if (c == 'D') {
        y--;
      } else if (c == 'L') {
        x--;
      } else if (c == 'R') {
        x++;
      }
    }
    return (x == 0 && y == 0);
  }
};
