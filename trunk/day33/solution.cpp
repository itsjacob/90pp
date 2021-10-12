class Solution
{
public:
  vector<int> getOrder(vector<vector<int>> &tasks)
  {
    std::vector<int> res;
    std::vector<std::vector<int>> tasksWithIdx;
    int ii{ 0 };
    for (auto const &task : tasks) {
      tasksWithIdx.push_back({ task[0], task[1], ii++ });
    }
    // sort the tasks besed on enqueueTime
    std::sort(tasksWithIdx.begin(), tasksWithIdx.end(),
              [](std::vector<int> &t1, std::vector<int> &t2) { return t1[0] < t2[0]; });

    // Min heap
    auto comp = [](std::vector<int> &t1, std::vector<int> &t2) {
      return (t1[0] > t2[0]) || (t1[0] == t2[0] && t1[1] > t2[1]);
    };
    std::vector<std::vector<int>> cache;
    std::make_heap(cache.begin(), cache.end(), comp);
    size_t time{ 0 };
    int idx = 0;
    for (auto const &t : tasks) {
      // If the CPU idle and we haven't reached the next task enqueue time, we jump to the next task enqueue time
      if (cache.empty()) {
        time = time > tasksWithIdx[idx][0] ? time : tasksWithIdx[idx][0];
      }
      while (idx < tasks.size() && tasksWithIdx[idx][0] <= time) {
        // Record processingTime and task id in the cache
        cache.push_back({ tasksWithIdx[idx][1], tasksWithIdx[idx][2] });
        std::push_heap(cache.begin(), cache.end(), comp);
        idx++;
      }
      // Consume one task on the top of the heap
      auto task = cache.front();
      std::pop_heap(cache.begin(), cache.end(), comp);
      cache.pop_back();
      time += task[0];
      res.emplace_back(task[1]);
    }
    return res;
  }
};
