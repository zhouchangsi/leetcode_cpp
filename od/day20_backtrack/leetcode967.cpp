// https://leetcode.cn/problems/numbers-with-same-consecutive-differences/
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> numsSameConsecDiff(int n, int k) {
    array<int, 10> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> res;
    vector<int> path;
    function<void()> backtrack = [&]() {
      if (path.size() == n) {
        stringstream ss;
        copy(path.begin(), path.end(), ostream_iterator<int>(ss, ""));
        int num;
        ss >> num;
        res.push_back(num);
        return;
      }

      const int cur = path.back();
      for (int i = 0; i < 10; i++) {
        if (i == cur - k || i == cur + k) {
          path.push_back(i);
          backtrack();
          path.pop_back();
        }
      }
    };

    for (int i = 1; i < 10; i++) {
      path.push_back(i);
      backtrack();
      path.pop_back();
    }

    return res;
  }
};