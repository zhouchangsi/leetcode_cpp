#include <gtest/gtest.h>
#include "leetcode.h"

using namespace std;
using namespace leetcode;

class Solution {
 public:
  vector<int> partitionLabels(string s) {
    int last[26];
    int length = s.size();
    for (int i = 0; i < length; i++) {
      last[s[i] - 'a'] = i;
    }
    vector<int> partition;
    int start = 0, end = 0;
    for (int i = 0; i < length; i++) {
      end = max(end, last[s[i] - 'a']);
      if (i == end) {
        partition.push_back(end - start + 1);
        start = end + 1;
      }
    }
    return partition;
  }
};

TEST(leetcode763, solution) {
  Solution s;
  vector<int> result = s.partitionLabels("ababcbacadefegdehijhklij");
  vector<int> expected = {9, 7, 8};
  EXPECT_EQ(result, expected);
}