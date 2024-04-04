#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int findShortestSubArray(vector<int>& nums) {
    unordered_map<int, int> count;
    unordered_map<int, int> first;
    unordered_map<int, int> last;
    int max_count = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int num = nums[i];
      if (count.find(num) == count.end()) {
        first[num] = i;
      }
      count[num]++;
      last[num] = i;
      max_count = max(max_count, count[num]);
    }

    int answer = nums.size();
    for (auto& [num, cnt] : count) {
      if (cnt == max_count) {
        answer = min(answer, last[num] - first[num] + 1);
      }
    }
    return answer;
  }
};