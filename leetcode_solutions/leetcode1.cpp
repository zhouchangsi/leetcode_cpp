#include "./leetcode/env.h"
#include <cassert>

class Solution
{
public:
  vector<int> twoSum(vector<int>& nums, int target)
  {
    unordered_map<int, int> m; // value:index
    for (int i = 0; i < nums.size(); ++i) {
      int v = nums[i];
      if (m.find(target - v) != m.end()) {
        return vector<int>({ m[target - v], i });
      }
      m[v] = i;
    }
    return vector<int>();
  }
};

int
main()
{
  return 0;
}