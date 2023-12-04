#include "common_headers.h"

using namespace std;

class Solution
{
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList)
  {
    unordered_set<string> set(wordList.begin(), wordList.end());
    if (!set.count(endWord))
      return 0;

    queue<string> que;
    que.emplace(beginWord);
    int step = 1;
    while (!que.empty()) {
      int sz = que.size(); // sz 表示当前层的单词个数
      for (int i = 0; i < sz; ++i) {
        string current_word = que.front();
        que.pop();
        if (current_word == endWord)
          return step;

        for (int j = 0; j < beginWord.size(); ++j) {
          for (char ch = 'a'; ch <= 'z'; ++ch) {
            if (ch != current_word[j]) {
              string next = current_word;
              // e.g. hit(current_word) -> *it, h*t, hi*
              next[j] = ch;
              if (set.count(next)) {
                que.emplace(next);
                set.erase(next);
              }
            }
          }
        }
      }
      ++step;
    }
    return 0;
  }
};

TEST(leetcode127, solution) {}