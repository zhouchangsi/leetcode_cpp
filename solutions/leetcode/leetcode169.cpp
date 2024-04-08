#include <vector>
using namespace std;
class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int candidate = 0, count = 0;
    for (auto cur : nums) {
      if (count == 0) candidate = cur;
      count += (candidate == cur) ? 1 : -1;
    }
    return candidate;
  }
};