#include <bits/stdc++.h>
using namespace std;

int main() {
  int num;
  vector<string> words;
  string chars;
  cin >> num;
  for (int i = 0; i < num; i++) {
    string word;
    cin >> word;
    words.push_back(word);
  }
  cin >> chars;

  //   int num = 4;
  //   vector<string> words = {"cat", "bt", "hat", "tree"};
  //   string chars = "at?ch";

  auto is_valid = [](const string &word, const string &chars) {
    unordered_map<char, int> word_count, chars_count;
    for (char c : word) {
      word_count[c]++;
    }
    for (char c : chars) {
      chars_count[c]++;
    }
    int need_question_mark = 0;
    for (const auto &[c, count] : word_count) {
      if (chars_count.find(c) == chars_count.end()) {
        need_question_mark += count;
      } else if (chars_count[c] < count) {
        need_question_mark += count - chars_count[c];
      }
    }
    return need_question_mark <= chars_count['?'];
  };

  int ans = 0;
  for (const string &word : words) {
    if (is_valid(word, chars)) {
      ans++;
    }
  }
  cout << ans << endl;

  return 0;
}
