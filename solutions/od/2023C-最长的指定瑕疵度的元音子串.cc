#include <bits/stdc++.h>
using namespace std;
void solve(int k, string line) {
  auto vowels =
      unordered_set<char>{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
  auto is_vowel = [&](char ch) { return vowels.count(ch); };

  int no_vowel = 0;
  const int& n = line.size();
  int l = 0;
  // 找到第一个元音
  while (l < n && !is_vowel(line[l])) l++;
  int r = l;

  int max_len = 0;
  for (r = l; r < n; r++) {
    if (!is_vowel(line[r])) {
      no_vowel++;
      continue;
    }

    if (no_vowel < k) continue;

    while (l <= r && no_vowel > k || !is_vowel(line[l])) {
      if (!is_vowel(line[l])) {
        no_vowel--;
      }
      l++;
    }

    if (no_vowel == k && is_vowel(line[l]) && is_vowel(line[r])) {
      max_len = max(max_len, r - l + 1);
    }
  }
  cout << max_len << '\n';
}

int main() {
  //   solve(2, "abira");
  //   solve(2, "abiraa");
  //   solve(2, "a");
  //   solve(2, "aiur");
  //   solve(2, "b");
  //   solve(2, "aaabaaabbaaabbbaaa");
  int k;
  cin >> k;
  string line;
  cin >> line;
  solve(k, line);
  return 0;
}