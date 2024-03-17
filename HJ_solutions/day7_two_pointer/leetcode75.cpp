#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;

class Solution {
 public:
  void sortColors(vector<int>& numbers) {
    int n = numbers.size();

    // i is the last index of 0
    int i = -1;
    for (int j = 0; j < n; ++j) {
      // 0 put to the left
      if (numbers[j] == 0) {
        i++;
        swap(numbers[i], numbers[j]);
      }
    }

    for (int j = i + 1; j < n; ++j) {
      // 1 put to after 0
      if (numbers[j] == 1) {
        i++;
        swap(numbers[i], numbers[j]);
      }
    }
  }
};

TEST(leetcode75, solution) {
  Solution s;
  vector<int> numbers = {2, 0, 2, 1, 1, 0};
  s.sortColors(numbers);
  EXPECT_EQ(numbers, vector<int>({0, 0, 1, 1, 2, 2}));
}