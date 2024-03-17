#include <cassert>

#include "./leetcode/env.h"

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> index_of_;  // value:index
    for (int i = 0; i < nums.size(); ++i) {
      int v = nums[i];
      if (index_of_.find(target - v) != index_of_.end()) {
        return vector<int>({index_of_[target - v], i});
      }
      index_of_[v] = i;
    }
    return {};
  }
};

int main() { return 0; }