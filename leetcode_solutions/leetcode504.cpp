#include "common_headers.h"

class Solution
{
public:
  string convertToBase7(int num)
  {
    if (num == 0) {
      return "0";
    }
    bool is_negative = num < 0;
    num = abs(num);
    string result;
    while (num > 0) {
      result.push_back('0' + num % 7);
      num /= 7;
    }
    if (is_negative) {
      result.push_back('-');
    }
    reverse(result.begin(), result.end());
    return result;
  }
};

TEST(leetcode504, sampleInputByProblem1)
{
  Solution solution;
  ASSERT_EQ("202", solution.convertToBase7(100));
}