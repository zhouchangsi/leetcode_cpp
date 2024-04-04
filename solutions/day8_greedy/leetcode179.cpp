// https://leetcode.com/problems/largest-number/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string largestNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end(), [](const int& a, const int& b) {
      return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    });
    stringstream ss;
    copy(nums.begin(), nums.end(), ostream_iterator<int>(ss, ""));
    string res = ss.str();
    return res[0] == '0' ? "0" : res;
  }
};