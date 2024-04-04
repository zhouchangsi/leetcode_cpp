// https://leetcode.cn/problems/task-scheduler/solutions/196302/tong-zi-by-popopop/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> m;
    for (char c : tasks) m[c]++;
    int max_freq = 0, max_count = 0;

    for (auto [task, count] : m) {
      if (count == max_freq) {
        max_count++;
      } else if (count > max_freq) {
        max_freq = count;
        max_count = 1;
      }
    }
    return max(                               //
        static_cast<int>(tasks.size()),       //
        (max_freq - 1) * (n + 1) + max_count  //
    );
  }
};