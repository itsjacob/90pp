class Solution
{
public:
  int numberOfRounds(string startTime, string finishTime)
  {
    std::istringstream ssStartTime(startTime);
    std::string token;
    std::vector<int> sTime;
    while (std::getline(ssStartTime, token, ':')) {
      sTime.push_back(std::stoi(token));
    }

    std::istringstream ssFinishTime(finishTime);
    std::vector<int> fTime;
    while (std::getline(ssFinishTime, token, ':')) {
      fTime.push_back(std::stoi(token));
    }

    // Increse the finishTime by one day if it is smaller than startTime
    if (sTime[0] > fTime[0] || (sTime[0] == fTime[0] && sTime[1] >= fTime[1])) {
      fTime[0] += 24;
    }

    // Round the startTime minutes up, round the finishTime minutes down
    sTime[1] = std::ceil(sTime[1] / 15.f) * 15;
    fTime[1] = std::floor(fTime[1] / 15.f) * 15;

    int res{ 0 };
    // After the rounding, there's no full-round game available
    if (sTime[0] == fTime[0] && sTime[1] >= fTime[1]) {
      res = 0;
    } else {
      res = (fTime[0] - sTime[0]) * 4 + (fTime[1] - sTime[1]) / 15;
    }

    return res;
  }
};
