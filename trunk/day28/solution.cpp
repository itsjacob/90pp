#define maxSlidingWindow maxSlidingWindow_maxHeap
class Solution {
public:
    vector<int> maxSlidingWindow_maxHeap(vector<int>& nums, int k) {
      std::unordered_map<int, int> window;
      std::vector<int> maxHeap;
      for (int ii = 0; ii < k; ii++) {
        window[nums[ii]]++;
        maxHeap.push_back(nums[ii]);
      }
      std::make_heap(maxHeap.begin(), maxHeap.end());
      
      std::vector<int> res;
      res.push_back(maxHeap.front());
      for (int ii = k, jj = 0; ii < nums.size(); ii++, jj++) {
        // Insert the new right element
        window[nums[ii]]++;
        maxHeap.push_back(nums[ii]);
        std::push_heap(maxHeap.begin(), maxHeap.end());
        
        // Remove the old left element
        // Update the map
        window[nums[jj]]--;
        if (window[nums[jj]] == 0) {
          window.erase(nums[jj]);
        }
        if (nums[jj] == maxHeap.front()) {
          // Update the heap if the to-be removed element is the max element
          do {
            std::pop_heap(maxHeap.begin(), maxHeap.end());
            maxHeap.pop_back();
            // Remove more if the current max in the heap is not inside the window
          } while (window.count(maxHeap.front()) == 0);  
        }
        res.push_back(maxHeap.front());
      }
      return res;
    }
};
