#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;

class Solution {
 public:
  vector<int> diffWaysToCompute(string expression) {
    vector<int> ans;
    for (int i = 0; i < expression.size(); i++) {
      char c = expression[i];
      if (c == '+' || c == '-' || c == '*') {
        vector<int> left = diffWaysToCompute(expression.substr(0, i));
        vector<int> right =
            diffWaysToCompute(expression.substr(i + 1, expression.size() - i));
        for (int l : left) {
          for (int r : right) {
            if (c == '+') {
              ans.push_back(l + r);
            } else if (c == '-') {
              ans.push_back(l - r);
            } else if (c == '*') {
              ans.push_back(l * r);
            }
          }
        }
      }
    }
    if (ans.empty()) {
      ans.push_back(stoi(expression));
    }
    return ans;
  }
};

void test_helper(string expression, vector<int> ans) {
  // answer may not be in order
  vector<int> res = Solution().diffWaysToCompute(expression);
  sort(res.begin(), res.end());
  sort(ans.begin(), ans.end());
  EXPECT_EQ(res, ans);
}

TEST(leetcode241, solution) {
  {
    string expression = "2-1-1";
    vector<int> ans = {0, 2};
    test_helper(expression, ans);
  }
  {
    string expression = "2*3-4*5";
    vector<int> ans = {-34, -14, -10, -10, 10};
    test_helper(expression, ans);
  }
}