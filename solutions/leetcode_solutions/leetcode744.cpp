#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;

class Solution {
 public:
  char nextGreatestLetter(vector<char>& letters, char target) {
    int left = 0;
    int right = letters.size() - 1;
    int mid;

    while (left <= right) {
      mid = (left + right) / 2;
      if (letters[mid] <= target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    if (left >= letters.size()) {
      return letters[0];
    } else {
      return letters[left];
    }
  }
};

TEST(leetcode744, solution) {
  Solution s;
  vector<char> letters;
  char target;
  char output;

  letters = {'c', 'f', 'j'};
  target = 'a';
  output = 'c';
  EXPECT_EQ(s.nextGreatestLetter(letters, target), output);

  letters = {'c', 'f', 'j'};
  target = 'c';
  output = 'f';
  EXPECT_EQ(s.nextGreatestLetter(letters, target), output);

  letters = {'c', 'f', 'j'};
  target = 'd';
  output = 'f';
  EXPECT_EQ(s.nextGreatestLetter(letters, target), output);

  letters = {'c', 'f', 'j'};
  target = 'g';
  output = 'j';
  EXPECT_EQ(s.nextGreatestLetter(letters, target), output);

  letters = {'c', 'f', 'j'};
  target = 'j';
  output = 'c';
  EXPECT_EQ(s.nextGreatestLetter(letters, target), output);

  letters = {'c', 'f', 'j'};
  target = 'k';
  output = 'c';
  EXPECT_EQ(s.nextGreatestLetter(letters, target), output);
}