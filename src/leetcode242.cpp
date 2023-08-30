#include "common_headers.h"

using namespace std;
class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
      return false;
    }
    vector<int> table(26, 0);
    for (auto& ch : s) {
      table[ch - 'a']++;
    }
    for (auto& ch : t) {
      table[ch - 'a']--;
      if (table[ch - 'a'] < 0) {
        return false;
      }
    }
    return true;
  }
};

TEST(leetcode242, ok) {
  {
    string s = "anagram";
    string t = "nagaram";
    Solution solution;
    bool res = solution.isAnagram(s, t);
    EXPECT_TRUE(res);
  }
  {
    string s = "rat";
    string t = "car";
    Solution solution;
    bool res = solution.isAnagram(s, t);
    EXPECT_FALSE(res);
  }
}
