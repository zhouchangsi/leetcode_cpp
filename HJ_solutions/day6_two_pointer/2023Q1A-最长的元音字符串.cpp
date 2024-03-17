/**
 * https://og7kl7g6h8.feishu.cn/docx/DfGhdGCncovLBExbIqCcBHcZnNd
 */
#include <bits/stdc++.h>
using namespace std;

int max_len_vowels(string s) {
  unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u',
                                'A', 'E', 'I', 'O', 'U'};

  int max_len = 0;
  for (int i = 0; i < s.size(); i++) {
    if (vowels.count(s[i])) {
      int j = i;
      while (j < s.size() && vowels.count(s[j])) {
        int len = j - i + 1;
        if (len > max_len) max_len = len;
        j++;
      }
      i = j;
    }
  }

  return max_len;
}

int main() {
  string s = "asdbuiodevauufgh";
  cin >> s;

  unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u',
                                'A', 'E', 'I', 'O', 'U'};

  cout << max_len_vowels(s) << endl;

  return 0;
}