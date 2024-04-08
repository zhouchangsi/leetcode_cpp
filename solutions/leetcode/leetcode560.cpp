#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    auto sum_count = unordered_map<int, int>{{0, 1}};
    int n = nums.size();
    int count = 0, sum = 0;
    for (auto num : nums) {
      sum += num;
      count += sum_count[sum - k];
      sum_count[sum]++;
    }
    return count;
  }
};