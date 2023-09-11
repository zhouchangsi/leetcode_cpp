#include "common_headers.h"

using namespace std;

class Solution {
 public:
  string findLongestWord(string s, vector<string>& dictionary) {
    string ans;
    for (auto& word : dictionary) {
      int i = 0, j = 0;
      while (i < s.size() && j < word.size()) {
        if (s[i] == word[j]) {
          j++;
        }
        i++;
      }
      if (j == word.size()) {
        if (word.size() > ans.size() ||
            (word.size() == ans.size() && word < ans)) {
          ans = word;
        }
      }
    }
    return ans;
  }
};

TEST(leetcode524, solution) {
  vector<string> dictionary = {"ale", "apple", "monkey", "plea"};
  EXPECT_EQ(Solution().findLongestWord("abpcplea", dictionary), "apple");
  dictionary = {"a", "b", "c"};
  EXPECT_EQ(Solution().findLongestWord("abpcplea", dictionary), "a");
}